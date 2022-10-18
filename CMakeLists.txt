cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 11)

project(car2dphysics_lib VERSION 0.1.0)

add_subdirectory(third_party/pybind11)
add_subdirectory(third_party/box2d)

set(CAR2DPHYSICS_SOURCE_FILES
    cpp/src/BaseCar.cpp
    cpp/src/FreeCar.cpp
    cpp/src/TrajectoryCar.cpp
    cpp/src/Trajectory.cpp
    cpp/src/BenchmarkCircuit8.cpp
    cpp/src/Singletons.cpp
)
set(CAR2DPHYSICS_HEADER_FILES
    cpp/include/BaseCar.h
    cpp/include/FreeCar.h
    cpp/include/TrajectoryCar.h
    cpp/include/Trajectory.h
    cpp/include/BenchmarkCircuit8.h
    cpp/include/Singletons.h
    cpp/include/defines.h
)

add_library(car2dphysics_lib ${CAR2DPHYSICS_SOURCE_FILES})

target_include_directories(
    car2dphysics_lib
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/box2d/include
    )

target_link_libraries(car2dphysics_lib PUBLIC box2d)    


pybind11_add_module(
    car2dphysics 
    cpp/src/car2dphysics_module.cpp
    ${CAR2DPHYSICS_SOURCE_FILES}
    )

target_include_directories(
    car2dphysics
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/box2d/include
    )

    target_link_libraries(car2dphysics PUBLIC car2dphysics_lib)    
