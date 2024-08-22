#pragma once
#include <opencv2/opencv.hpp>
#include <math.h>
#include <vector>
#include "world_item.h"

struct Lidar : public WorldItem {
    float range_min = 0.1;
    float range_max = 750;
    float angle_min = -M_PI/4;
    float angle_max = M_PI/4;
    float num_beams = 25;
    float beam_increment = 0.1;

    Lidar(GridMap* g, WorldItem* p, Isometry2f iso);

    void draw(cv::Mat& dest);

    cv::Point beam_start(float beam_angle);

    cv::Point beam_end(float beam_angle);

    ~Lidar();
};
