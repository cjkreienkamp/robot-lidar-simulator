cmake_minimum_required(VERSION 2.8.3)
project(chris)

#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

set(CXX_STANDARD c++17)

include_directories(/usr/include/eigen3)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(src)