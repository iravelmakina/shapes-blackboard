#include "Rectangle.h"


Rectangle::Rectangle(const size_t id, const double x, const double y, const double width,
                     const double height) : Figure(id, x, y), width(width), height(height) {
}


void Rectangle::setWidth(const double value) {
    width = value;
}


double Rectangle::getWidth() const {
    return width;
}


void Rectangle::setHeight(const double value) {
    height = value;
}


double Rectangle::getHeight() const {
    return height;
}


void Rectangle::draw() {

}
