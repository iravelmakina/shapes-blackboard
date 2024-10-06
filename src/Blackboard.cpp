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


void Blackboard::add(const int typeId, const int x, const int y, const int param1, const int param2, const
                     int param3, const int param4) {
    if (canPlaceFigure(x, y, param1, param2, param3, param4, typeId)) {
        if (std::unique_ptr<Figure> figure = createFigure(typeId, x, y, param1, param2, param3, param4)) {
            if (!isDuplicateFigure(figure)) {
                figure->setId(generateFigureId());
                currentFigures.push_back(std::move(figure));
            } else {
                std::cout << "Error: Duplicate figure cannot be placed on the board." << std::endl;
            }
        } else {
            std::cout << "Error: Figure creation failed." << std::endl;
        }
    } else {
        std::cout << "Error: Figure cannot be placed on the board." << std::endl;
    }
}


void Blackboard::undo() {
    if (!currentFigures.empty()) {
        currentFigures.pop_back();
    } else {
        std::cout << "Add some figures first to remove them!" << std::endl;
    }
}


void Blackboard::clear() {
    if (!currentFigures.empty()) {
        currentFigures.clear();
        resetGrid();
    } else {
        std::cout << "Blackboard is already clean!" << std::endl;
    }
}


void Blackboard::save(const std::string &filePath) const {
    std::ofstream outFile(filePath);
    if (!outFile) {
        std::cout << "Error: Could not open file for writing: " << filePath << std::endl;
        return;
    }

    outFile << width << " " << height << "\n";
    for (const std::unique_ptr<Figure> &figure: currentFigures) {
        outFile << figure->getType() << " " << figure->getCoordinates() << "\n";
    }
    outFile.close();
    std::cout << "Saved!" << std::endl;
}


void Blackboard::load(const std::string &filePath) { // file validation
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cout << "Error: Could not open file for reading: " << filePath << std::endl;
        return;
    }

    if (!(inFile >> width >> height) || width <= 0 || height <= 0) {
        std::cout << "Error: Invalid blackboard dimensions in file: " << filePath << std::endl;
        return;
    }

    grid.resize(height, std::vector(width, '.'));
    currentFigures.clear();

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int typeId;
        if (!(iss >> typeId)) {
            std::cout << "Error: Invalid figure type ID in file: " << filePath << std::endl;
            return;
        }
        parseAndAddFigure(iss, typeId);

    }
    inFile.close();
    std::cout << "Loaded!" << std::endl;
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
            return (x >= 0 && x < width && y >= 0 && y < height) || (param1 >= 0 && param1 < width && param2 >= 0 && param2 < height);
        case 1:
            return x - param1 < width || x + param1 >= 0 || y - param1 < height || y + param1 >= 0;
        case 2:
            return (x >= 0 && x < width && y >= 0 && y < height) || (param1 >= 0 && param1 < width && param2 >= 0 && param2 < height);
        case 3:
            return (x >= 0 && x < width && y >= 0 && y < height) || (param1 >= 0 && param1 < width && param2 >= 0 && param2 < height) || (param3 >= 0 && param3 < width && param4 >= 0 && param4 < height);
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


void Blackboard::parseAndAddFigure(std::istringstream &iss, const int typeId) {
    int x, y, param1, param2 = 0, param3 = 0, param4 = 0;
    iss >> x >> y;

    switch (typeId) {
        case 0:
            if (!(iss >> param1 >> param2)) {
                std::cout << "Error: Invalid parameters for Line." << std::endl;
                return;
            }
        add(typeId, x, y, param1, param2);
        break;
        case 1:
            if (!(iss >> param1)) {
                std::cout << "Error: Invalid parameters for Circle." << std::endl;
                return;
            }
        add(typeId, x, y, param1);
        break;
        case 2:
            if (!(iss >> param1 >> param2)) {
                std::cout << "Error: Invalid parameters for Rectangle." << std::endl;
                return;
            }
        add(typeId, x, y, param1, param2);
        break;
        case 3:
            if (!(iss >> param1 >> param2 >> param3 >> param4)) {
                std::cout << "Error: Invalid parameters for Triangle." << std::endl;
                return;
            }
        add(typeId, x, y, param1, param2, param3, param4);
        break;
        default:
            std::cout << "Error: Unknown figure type: " << typeId << std::endl;
    }
}
