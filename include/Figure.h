#pragma once


#include <cstddef>
#include <ostream>


class Figure {
public:
    enum FigureType {
        Line,
        Circle,
        Rectangle,
        Triangle
    };

    Figure(size_t id, int x, int y);

    virtual ~Figure() = default;

    void setId(size_t value);

    virtual FigureType getType() const = 0;

    virtual std::string getCoordinates() const = 0;

    size_t getId() const;

    void setX(int value);

    int getX() const;

    void setY(int value);

    int getY() const;

    virtual void draw(std::vector<std::vector<char>> &grid) = 0;

    virtual void print(std::ostream& os) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Figure &figure);

    virtual bool operator==(const Figure &other) const = 0;
private:
    size_t id = 0;
    int x, y;
};
