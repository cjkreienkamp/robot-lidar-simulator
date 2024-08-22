#include <opencv2/opencv.hpp>
#include <Eigen/Geometry>
#include <Eigen/Core>
#include "grid_map.h"
#include "world_item.h"
#include "lidar.h"

using namespace std;
using namespace Eigen;

int show_canvas(cv::Mat& canvas) {
    cv::imshow("canvas", canvas);
    int key = cv::waitKey(0);
    if (key==27) exit(0);
    return key;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << argv[0] << " <image_file> <resolution>" << endl;
        return -1;
    }

    GridMap grid_map;
    cv::Mat canvas;
    
    const char* filename = argv[1];
    grid_map.load_from_image(filename);

    Isometry2f initial_iso = Isometry2f::Identity();
    initial_iso.translation().x() = grid_map.origin[0];
    initial_iso.translation().y() = grid_map.origin[1];
    WorldItem robot(&grid_map, nullptr, initial_iso);

    initial_iso = Isometry2f::Identity();
    initial_iso.translation().x() = -15;
    Lidar top_lidar(&grid_map, &robot, initial_iso);

    while(true) {
        grid_map.draw(canvas);
        robot.draw(canvas);
        top_lidar.draw(canvas);
        int key_pressed = show_canvas(canvas);
        
        switch(key_pressed) {
            case 81: // left
                robot.rotate(-0.1);
                break;
            case 82: // up
                robot.move(1);
                break;
            case 83: // right
                robot.rotate(0.1);
                break;
            case 84: // down
                robot.move(-1);
                break;
            case 32: // space
            default:;
        }
    }
}
