cmake_minimum_required(VERSION 3.29)
project(shapes_blackboard)

set(CMAKE_CXX_STANDARD 20)

add_executable(shapes_blackboard main.cpp
        Figure.h
        Figure.cpp
        Circle.h
        Circle.cpp
        Line.h
        Line.cpp
        Rectangle.h
        Rectangle.cpp
        Triangle.h
        Triangle.cpp
        Blackboard.h
        Blackboard.cpp
        BresenhamAlgorithm.cpp
        BresenhamAlgorithm.h
        CLI.h
        CLI.cpp
)
