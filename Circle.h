#pragma once
#include "Figure.h"


class Circle : Figure {
public:
    Circle(size_t id, double x, double y, double radius);

    void draw() override;

    void setRadius(double input);

    double getRadius() const;

private:
    double radius;
};
