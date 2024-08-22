add_executable(simulator
    simulator.cpp
    grid_map.cpp
    world_item.cpp
    lidar.cpp)

target_link_libraries(simulator
    ${OpenCV_LIBS})