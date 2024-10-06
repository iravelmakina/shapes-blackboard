#include "Blackboard.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"


size_t Blackboard::nextFigureId = 1;


Blackboard::Blackboard(const size_t width, const size_t height) : width(width), height(height),
                                                                  grid(height, std::vector(width, '.')) {
}


void Blackboard::setWidth(const size_t value) {
    width = value;
}


size_t Blackboard::getWidth() const {
    return width;
}


void Blackboard::setHeight(const size_t value) {
    height = value;
}


size_t Blackboard::getHeight() const {
    return height;
}


size_t Blackboard::generateFigureId() {
    return nextFigureId++;
}
