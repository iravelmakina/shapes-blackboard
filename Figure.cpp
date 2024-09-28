#include "Figure.h"


Figure::Figure(const size_t id, const double x, const double y) : id(id), x(x), y(y) {}


void Figure::setId(const size_t input) {
    id = input;
}


size_t Figure::getId() const {
    return id;
}


void Figure::setX(const double value) {
    x = value;
}


double Figure::getX() const {
    return x;
}


void Figure::setY(const double value) {
    y = value;
}


double Figure::getY() const {
    return y;
}
