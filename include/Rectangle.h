#pragma once
#include "BresenhamAlgorithm.h"
#include "Figure.h"


#include <cstddef>
#include <ostream>


class Rectangle : public Figure {
public:
    Rectangle(size_t id, int x, int y, int x2, int y2);

    FigureType getType() const override;

    std::string getCoordinates() const override;

    void setX2(int value);

    int getX2() const;

    void setY2(int value);

    int getY2() const;

    void draw(std::vector<std::vector<char>> &grid) override;

    bool operator==(const Figure &other) const override;

    void print(std::ostream &os) const override;

private:
    int x2, y2;
};
