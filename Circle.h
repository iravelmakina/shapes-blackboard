#pragma once
#include "Figure.h"


class Circle : Figure {
public:
    Circle(const double x, const double y, const double radius) : Figure(x, y), radius(radius) {}

    void draw() override;

    void setRadius(double input);

    double getRadius() const;

private:
    double radius;
};
