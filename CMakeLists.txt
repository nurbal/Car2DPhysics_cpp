cmake_minimum_required(VERSION 3.0.0)

project(car2dphysics VERSION 0.1.0)

add_subdirectory(third_party/pybind11)
pybind11_add_module(
    car2dphysics 
    cpp/src/car2dphysics_module.cpp
    cpp/src/BaseCar.cpp
    cpp/src/FreeCar.cpp
    cpp/src/MovingCar.cpp
    cpp/src/TrajectoryCar.cpp
    cpp/src/Trajectory.cpp
    )

target_include_directories(
    car2dphysics
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/box2d/include
    # ${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include
    )