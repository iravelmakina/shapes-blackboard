#include "Line.h"


#include <sstream>


Line::Line(const size_t id, const int x, const int y, const int x2, const int y2) : Figure(id, x, y), x2(x2), y2(y2) {
}


Figure::FigureType Line::getType() const {
    return FigureType::Line;
}


std::string Line::getCoordinates() const {
    std::ostringstream oss;
    oss << getX() << " " << getY() << " " << getX2() << " " << getY2();
    return oss.str();
}


void Line::setX2(const int value) {
    x2 = value;
}


int Line::getX2() const {
    return x2;
}


void Line::setY2(const int value) {
    y2 = value;
}


int Line::getY2() const {
    return y2;
};


void Line::draw(std::vector<std::vector<char>> &grid) {
    BresenhamAlgorithm::drawLine(grid, getX(), getY(), getX2(), getY2());
}


bool Line::operator==(const Figure &other) const {
    if (const Line* otherLine = dynamic_cast<const Line*>(&other)) {
        return getCoordinates() == otherLine->getCoordinates();
    }
    return false;
}


void Line::print(std::ostream &os) const {
    os << "Line(ID: " << getId() << ", First endpoint coordinates: (" << getX() << ", " << getY() << ")"
            << ", Second endpoint coordinates: (" << getX2() << ", " << getY2() << "))";
}
