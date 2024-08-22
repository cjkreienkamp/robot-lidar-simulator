#include "world_item.h"



WorldItem::WorldItem(GridMap* g, WorldItem* p, Isometry2f iso)
    : grid_map(g), parent(p), pose_in_parent(iso) {
        origin.x = global_pose().translation().x();
        origin.y = global_pose().translation().y();
    }

Isometry2f WorldItem::global_pose() const {
    if (!parent) return pose_in_parent;
    return parent->global_pose() * pose_in_parent;
}

void WorldItem::draw(cv::Mat& dest) {
    origin.x = global_pose().translation().x();
    origin.y = global_pose().translation().y();
    cv::circle(dest, origin, radius, cv::Scalar(0,0,0));
}

void WorldItem::rotate(float angle) {
    pose_in_parent.linear() = pose_in_parent.linear()*Rotation2Df(angle).matrix();
}

void WorldItem::move(float dist) {
    float angle = atan2( pose_in_parent(1,0) , pose_in_parent(0,0) );
    float newOriginX, newOriginY;
    newOriginX = pose_in_parent.translation().x() + dist*cos(angle);
    newOriginY = pose_in_parent.translation().y() + dist*sin(angle);
    if (checkCollision(cv::Point(newOriginX,newOriginY))) {
        std::cerr<<"[WARN] collision, cannot move"<<std::endl;
    } else {
        pose_in_parent.translation().x() = newOriginX;
        pose_in_parent.translation().y() = newOriginY;
    }
}

bool WorldItem::checkCollision(cv::Point newOrigin) const {
    for (int x = -radius; x<=radius; x++) {
        for (int y = -radius; y<=radius; y++) {
            if (x*x + y*y > radius*radius) continue;
            Vector2i offset = {x, y};
            Vector2i position = Vector2i{newOrigin.x, newOrigin.y} + offset;
            if (!grid_map->inside(position)) return true;
            if (grid_map->at(position) < 127) return true;
        }
    }
    return false;
}

WorldItem::~WorldItem() {}
