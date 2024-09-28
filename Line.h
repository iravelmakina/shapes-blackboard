#pragma once
#include "Figure.h"


class Line : Figure {
public:
    Line(size_t id, double x, double y, double x2, double y2);

    void setX2(double value);

    double getX2() const;

    void setY2(double value);

    double getY2() const;

    void draw() override;

private:
    double x2;
    double y2;
};
