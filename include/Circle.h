#pragma once
#include <ostream>

#include "Figure.h"


class Circle : public Figure {
public:
    Circle(size_t id, int x, int y, int radius);

    FigureType getType() const override;

    std::string getCoordinates() const override;

    void setRadius(int value);

    int getRadius() const;

    void draw(std::vector<std::vector<char>> &grid) override;

    bool operator==(const Figure &other) const override;

    void print(std::ostream &os) const override;

private:
    int radius;
};
