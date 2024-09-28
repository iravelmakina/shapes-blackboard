#pragma once
#include "Figure.h"


class Rectangle : Figure {
public:
    Rectangle(size_t id, double x, double y, double width, double height);

    void setWidth(double value);

    double getWidth() const;

    void setHeight(double value);

    double getHeight() const;

    void draw() override;

private:
    double width;
    double height;
};
