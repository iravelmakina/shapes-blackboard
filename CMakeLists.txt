cmake_minimum_required(VERSION 3.29)
project(shapes_blackboard)

set(CMAKE_CXX_STANDARD 20)

add_executable(shapes_blackboard main.cpp
        Figure.h
        Figure.cpp)
