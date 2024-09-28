#pragma once
#include "Figure.h"


class Triangle : Figure {
public:
    Triangle(size_t id, double x, double y, double baseLength, double height);

    void setBaseLength(double value);

    double getBaseLength() const;

    void setHeight(double value);

    double getHeight() const;

    void draw() override;

private:
    double baseLength;
    double height;
};
