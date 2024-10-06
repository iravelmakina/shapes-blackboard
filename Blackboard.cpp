#include "Blackboard.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"


size_t Blackboard::nextFigureId = 1;


Blackboard::Blackboard(const size_t width, const size_t height) : width(width), height(height),
                                                                  grid(height, std::vector(width, '.')) {
}


void Blackboard::setWidth(const size_t value) {
    width = value;
}


size_t Blackboard::getWidth() const {
    return width;
}


void Blackboard::setHeight(const size_t value) {
    height = value;
}


size_t Blackboard::getHeight() const {
    return height;
}


size_t Blackboard::generateFigureId() {
    return nextFigureId++;
}


// ----------------------------------------------------------------------------
void Blackboard::draw() {
    resetGrid();
    for (const std::unique_ptr<Figure> &figure: currentFigures) {
        figure->draw(grid);
    }
    print();
}


void Blackboard::list() const {
    if (!currentFigures.empty()) {
        for (const std::unique_ptr<Figure> &figure: currentFigures) {
            std::cout << *figure << std::endl;
        }
    } else {
        std::cout << "There are no figures yet!" << std::endl;
    }
}


void Blackboard::shapes() {
    std::cout << "Line: (x, y) for first endpoint, (x, y) for second endpoint;" << std::endl;
    std::cout << "Circle: (x, y) for center, radius;" << std::endl;
    std::cout << "Rectangle: (x, y) for top-left vertex, (x, y) for bottom-right vertex;" << std::endl;
    std::cout << "Triangle: (x, y) for first vertex, (x, y) for second vertex, (x, y) for third vertex;" << std::endl;
}


// ----------------------------------------------------------------------------
void Blackboard::print() const {
    for (const std::vector<char> &row: grid) {
        for (const char c: row) {
            std::cout << c;
        }
        std::cout << "\n";
    }
}


void Blackboard::resetGrid() {
    for (std::vector<char> &row: grid) {
        std::fill(row.begin(), row.end(), '.');
    }
}
