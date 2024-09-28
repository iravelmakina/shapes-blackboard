#include "Circle.h"


Circle::Circle(const size_t id, const double x, const double y, const double radius) : Figure(id, x, y), radius(radius) {}


void Circle::setRadius(const double input) {
    radius = input;
}


double Circle::getRadius() const {
    return radius;
}


void Circle::draw() override {}
