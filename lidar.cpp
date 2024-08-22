#include "lidar.h"

Lidar::Lidar(GridMap* g, WorldItem* p, Isometry2f iso)
            : WorldItem(g, p, iso) {}

void Lidar::draw(cv::Mat& dest) {
    origin.x = global_pose().translation().x();
    origin.y = global_pose().translation().y();
    float angle;
    float angle_increment = (angle_max - angle_min) / num_beams;
    float angle_offset = atan2( global_pose()(1,0) , global_pose()(0,0) );
    for(int i=0; i<num_beams; i++) {
        angle = angle_min + i*angle_increment + angle_offset;
        cv::line(dest, beam_start(angle), beam_end(angle), cv::Scalar(0,0,0));
    }
    cv::circle(dest, origin, 10, cv::Scalar(0,0,0));
}

cv::Point Lidar::beam_start(float angle) {
    cv::Point beam_start;
    beam_start.x = origin.x + range_min*cos(angle);
    beam_start.y = origin.y + range_min*sin(angle);
    return beam_start;
}

cv::Point Lidar::beam_end(float angle) {
    cv::Point beam_end;
    float range = range_min;
    while (range < range_max) {
        beam_end.x = origin.x + range*cos(angle);
        beam_end.y = origin.y + range*sin(angle);
        if (!grid_map->inside(beam_end)) { break; }
        if (grid_map->at(beam_end) < 127) { break; }
        range += beam_increment;
    }
    return beam_end;
}

Lidar::~Lidar() {}
