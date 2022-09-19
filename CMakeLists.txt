cmake_minimum_required(VERSION 3.0.0)

project(car2dphysics VERSION 0.1.0)

add_subdirectory(third_party/pybind11)
pybind11_add_module(car2dphysics cpp/src/car2dphysics_module.cpp)

