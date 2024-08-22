#pragma once
#include <Eigen/Core>
#include <opencv2/opencv.hpp>

using namespace Eigen;

struct GridMap {
    int rows;
    int cols;
    Vector2i origin;
    uint8_t* values;

    GridMap();

    inline const bool inside(int r, int c) const {
        if ( r>0 && r<rows && c>0 && c<cols) {return true;}
        return false;
    }
    inline const bool inside(Vector2i pos) const {return inside(pos[1], pos[0]);}
    inline const bool inside(cv::Point pos) const {return inside(pos.y, pos.x);}

    inline const uint8_t& at(int r, int c) const {return values[r*cols+c];}
    inline const uint8_t& at(Vector2i pos) const {return at(pos[1], pos[0]);}
    inline const uint8_t& at(cv::Point pos) const {return at(pos.y, pos.x);}

    void load_from_image(const char* filename);
    void draw(cv::Mat& dest);

    ~GridMap();
};
