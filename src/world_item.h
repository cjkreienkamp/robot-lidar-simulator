#pragma once
#include <Eigen/Geometry>
#include <Eigen/Core>
#include "grid_map.h"

using namespace Eigen;

struct WorldItem {
    const GridMap* grid_map;
    WorldItem* parent;
    Isometry2f pose_in_parent;
    cv::Point origin;
    float radius = 30;
    
    WorldItem(GridMap* g, WorldItem* p, Isometry2f iso = Isometry2f::Identity());
    
    Isometry2f global_pose() const;

    void draw(cv::Mat& canvas);

    void rotate(float angle);

    void move(float distance);

    bool checkCollision(cv::Point newOrigin) const;

    ~WorldItem();
};
