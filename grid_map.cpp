#include "grid_map.h"



GridMap::GridMap() {}

void GridMap::load_from_image(const char *filename)
{
    cv::Mat map_raw = cv::imread(filename);
    cv::Mat map_gray;
    cv::cvtColor(map_raw, map_gray, cv::COLOR_BGR2GRAY);

    rows = map_gray.rows;
    cols = map_gray.cols;
    values = new uint8_t[rows*cols];
    origin[0] = cols/2;
    origin[1] = rows/2;

    memcpy(values, map_gray.data, rows*cols);
}

void GridMap::draw(cv::Mat& dest) {
    dest = cv::Mat(rows, cols, CV_8UC1);
    memcpy(dest.data, values, rows*cols);
}

GridMap::~GridMap() {}