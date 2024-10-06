#include "Rectangle.h"

#include <iostream>
#include <sstream>


Rectangle::Rectangle(const size_t id, const int x, const int y, const int x2,
                     const int y2) : Figure(id, x, y), x2(x2), y2(y2) {
}


Figure::FigureType Rectangle::getType() const {
    return FigureType::Rectangle;
}


std::string Rectangle::getCoordinates() const {
    std::ostringstream oss;
    oss << getX() << " " << getY() << " " << getX2() << " " << getY2();
    return oss.str();
}


void Rectangle::setX2(const int value) {
    x2 = value;
}


int Rectangle::getX2() const {
    return x2;
}


void Rectangle::setY2(const int value) {
    y2 = value;
}


int Rectangle::getY2() const {
    return y2;
}


void Rectangle::draw(std::vector<std::vector<char> > &grid) {
    BresenhamAlgorithm::drawLine(grid, getX(), getY(), getX2(), getY());
    BresenhamAlgorithm::drawLine(grid, getX2(), getY(), getX2(), getY2());
    BresenhamAlgorithm::drawLine(grid, getX2(), getY2(), getX(), getY2());
    BresenhamAlgorithm::drawLine(grid, getX(), getY2(), getX(), getY());
}


bool Rectangle::operator==(const Figure &other) const {
    if (const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other)) {
        return getCoordinates() == otherRectangle->getCoordinates();
    }
    return false;
}


void Rectangle::print(std::ostream &os) const {
    os << "Rectangle(ID: " << getId() << ", Coordinates of top-left corner (" << getX() << ", " << getY() <<
            ")" << ", Coordinates of top-right corner (" << getX2() << ", " << getY() <<
            ", Coordinates of bottom-left corner (" << getX() << ", " << getY2() <<
            ", Coordinates of bottom-right corner (" << getX2() << ", " << getY2() << "))";
}
