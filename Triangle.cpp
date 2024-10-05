#include "Triangle.h"


#include <iostream>
#include <sstream>


Triangle::Triangle(const size_t id, const int x, const int y, const int x2, const int y2, const int x3,
                   const int y3) : Figure(id, x, y), x2(x2), y2(y2), x3(x3), y3(y3) {
}


Figure::FigureType Triangle::getType() const {
    return FigureType::Triangle;
}


std::string Triangle::getCoordinates() const {
    std::ostringstream oss;
    oss << getX() << " " << getY() << " " << getX2() << " " << getY2() << " " << getX3() << " " << getY3();
    return oss.str();
}


void Triangle::setX2(const int value) {
    x2 = value;
}


int Triangle::getX2() const {
    return x2;
}


void Triangle::setY2(const int value) {
    y2 = value;
}


int Triangle::getY2() const {
    return y2;
}


void Triangle::setX3(const int value) {
    x3 = value;
}


int Triangle::getX3() const {
    return x3;
}


void Triangle::setY3(const int value) {
    y3 = value;
}


int Triangle::getY3() const {
    return y3;
}


void Triangle::draw(std::vector<std::vector<char> > &grid) {
    BresenhamAlgorithm::drawLine(grid, getX(), getY(), getX2(), getY2());
    BresenhamAlgorithm::drawLine(grid, getX2(), getY2(), getX3(), getY3());
    BresenhamAlgorithm::drawLine(grid, getX3(), getY3(), getX(), getY());
}


bool Triangle::operator==(const Figure &other) const {
    if (const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other)) {
        return getCoordinates() == otherTriangle->getCoordinates();
    }
    return false;
}


void Triangle::print(std::ostream &os) const {
    os << "Triangle(ID: " << getId() << ", Coordinates of vertex 1: (" << getX() << ", " << getY() << ")"
            << ", Coordinates of vertex 2: (" << getX2() << ", " << getY2() << ")"
            << ", Coordinates of vertex 3: (" << getX3() << ", " << getY3() << "))";
}
