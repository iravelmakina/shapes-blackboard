#include "Figure.h"


Figure::Figure(const size_t id, const int x, const int y) : id(id), x(x), y(y) {}


void Figure::setId(const size_t value) {
    id = value;
}


size_t Figure::getId() const {
    return id;
}


void Figure::setX(const int value) {
    x = value;
}


int Figure::getX() const {
    return x;
}


void Figure::setY(const int value) {
    y = value;
}


int Figure::getY() const {
    return y;
}


std::ostream& operator<<(std::ostream& os, const Figure& figure) {
    figure.print(os);
    return os;
}