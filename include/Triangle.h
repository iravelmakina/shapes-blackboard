#pragma once
#include "BresenhamAlgorithm.h"
#include "Figure.h"


#include <ostream>


class Triangle : public Figure {
public:
    Triangle(size_t id, int x, int y, int x2, int y2, int x3, int y3);

    FigureType getType() const override;

    std::string getCoordinates() const override;

    void setX2(int value);

    int getX2() const;

    void setY2(int value);

    int getY2() const;

    void setX3(int value);

    int getX3() const;

    void setY3(int value);

    int getY3() const;

    void draw(std::vector<std::vector<char>> &grid) override;

    bool operator==(const Figure &other) const override;

    void print(std::ostream &os) const override;

private:
    int x2, y2, x3, y3;
};
