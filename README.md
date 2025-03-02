# Robot LiDAR Simulator

This project is a C++ application that simulates a robot equipped with LiDAR sensors. Users can control the robot within a predefined environment and visualize the LiDAR data in real-time.

## Features

- **Robot Simulation**: Navigate a robot within a simulated environment using keyboard controls.
- **LiDAR Visualization**: Real-time display of LiDAR sensor data as the robot moves.

## Prerequisites

- **Operating System**: Linux-based systems (e.g., Ubuntu)
- **Dependencies**:
  - C++ Compiler (e.g., g++)
  - CMake
  - OpenCV library

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/cjkreienkamp/robot-lidar-simulator.git
   cd robot-lidar-simulator

2. **Create a build directory**:
   ```bash
   mkdir build
   cd build

3. **Generate build files using CMake**:
   ```bash
   cmake ..

4. **Compile the application**:
   ```bash
   make

## Usage

1. **Run the simulator**:
   From the build directory, execute:
   ```bash
   ./src/simulator ../map.png

2. Control the robot:
   - **Arrow Keys**:
     - Up/Down: Move forward/backward
     - Left/Right: Rotate left/right
   - **Exit**: Press the `ESC` key to exit the simulation.

## File Structure

- `src/`: Contains the source code for the simulator.
- `map.png`: Image file representing the environment map.
- `CMakeLists.txt`: CMake configuration file.
- `README.md`: Project documentation file.
