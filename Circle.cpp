#include "Circle.h"
#include "BresenhamAlgorithm.h"
#include <iostream>
#include <sstream>


Circle::Circle(const size_t id, const int x, const int y, const int radius) : Figure(id, x, y), radius(radius) {
}


Figure::FigureType Circle::getType() const {
    return FigureType::Circle;
}


std::string Circle::getCoordinates() const {
    std::ostringstream oss;
    oss << getX() << " " << getY() << " " << getRadius();
    return oss.str();
}



void Circle::setRadius(const int value) {
    radius = value;
}


int Circle::getRadius() const {
    return radius;
}


void Circle::draw(std::vector<std::vector<char>> &grid) {
    BresenhamAlgorithm::drawCircle(grid, getX(), getY(), radius);
}


bool Circle::operator==(const Figure &other) const {
    if (const Circle* otherCircle = dynamic_cast<const Circle*>(&other)) {
        return getCoordinates() == otherCircle->getCoordinates()  && getRadius() == otherCircle->getRadius();
    }
    return false;
}


void Circle::print(std::ostream &os) const {
    os << "Circle(ID: " << getId() << ", Coordinates: (" << getX() << ", " << getY() << ")" <<
            ", Radius: " << getRadius() << "))";
}
