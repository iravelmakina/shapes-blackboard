#include "Circle.h"


void Circle::setRadius(const double input) {
    radius = input;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::draw() override {}
