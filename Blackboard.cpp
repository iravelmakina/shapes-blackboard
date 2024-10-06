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


std::unique_ptr<Figure> Blackboard::createFigure(const int typeId, const int x, const int y,
                                                 const int param1, const int param2, const
                                                 int param3, const int param4) {
    switch (typeId) {
        case 0:
            return std::make_unique<Line>(0, x, y, param1, param2);
        case 1:
            return std::make_unique<Circle>(0, x, y, param1);
        case 2:
            return std::make_unique<Rectangle>(0, x, y, param1, param2);
        case 3:
            return std::make_unique<Triangle>(0, x, y, param1, param2, param3, param4);
        default:
            return nullptr;
    }
}


bool Blackboard::canPlaceFigure(const int x, const int y, const int param1, const int param2, const int param3, const int param4, const int typeId) const {
    switch (typeId) {
        case 0:
            return x >= 0 && x < width && y >= 0 && y < height && param1 >= 0 && param1 < width && param2 >= 0 && param2 < height;
        case 1:
            return x >= 0 && x < width && y >= 0 && y < height && param1 > 0 && x + param1 < width && y + param1 < height;
        case 2:
            return x >= 0 && x < width && y >= 0 && y < height && param1 >= 0 && param1 < width && param2 >= 0 && param2 < height;
        case 3:
            return x >= 0 && x < width && y >= 0 && y < height && param1 >= 0 && param1 < width && param2 >= 0 && param2 < height && param3 >= 0 && param3 < width && param4 >= 0 && param4 < height;
        default:
            return false;
    }
}


bool Blackboard::isDuplicateFigure(const std::unique_ptr<Figure> &newFigure) const {
    for (const std::unique_ptr<Figure> &figure: currentFigures) {
        if (*figure == *newFigure) {
            return true;
        }
    }
    return false;
}

