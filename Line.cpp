#include "Line.h"


Line::Line(const size_t id, const double x, const double y, const double x2, const double y2) : Figure(id, x, y), x2(x2), y2(y2) {
}


void Line::setX2(const double value) {
    x2 = value;
}


double Line::getX2() const {
    return x2;
}


void Line::setY2(const double value) {
    y2 = value;
}


double Line::getY2() const {
    return y2;
};


void Line::draw() {

}
