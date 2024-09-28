#include "Triangle.h"


Triangle::Triangle(const size_t id, const double x, const double y, const double baseLength,
                   const double height) : Figure(id, x, y), baseLength(baseLength), height(height) {
}


void Triangle::setBaseLength(double value) {
    baseLength = value;
}


double Triangle::getBaseLength() const {
    return baseLength;
}


void Triangle::setHeight(double value) {
    height = value;
}


double Triangle::getHeight() const {
    return height;
}


void Triangle::draw() override {

}
