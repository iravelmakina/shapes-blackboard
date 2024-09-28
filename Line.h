#pragma once
#include "Figure.h"


class Line : Figure {
public:
    Line(size_t id, double x, double y, double x2, double y2);

    void setX2(double input);

    double getX2() const;

    void setY2(double input);

    double getY2() const;

private:
    double x2;

    double y2;
};
