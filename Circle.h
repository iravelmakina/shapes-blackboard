#pragma once
#include "Figure.h"


class Circle : Figure {
public:
    Circle(size_t id, double x, double y, double radius);

    void setRadius(double value);

    double getRadius() const;

    void draw() override;

private:
    double radius;
};
