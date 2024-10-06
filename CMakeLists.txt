cmake_minimum_required(VERSION 3.29)
project(shapes_blackboard)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(shapes_blackboard src/main.cpp
        src/Figure.cpp
        src/Line.cpp
        src/Circle.cpp
        src/Rectangle.cpp
        src/Triangle.cpp
        src/Blackboard.cpp
        src/BresenhamAlgorithm.cpp
        src/CLI.cpp
)
