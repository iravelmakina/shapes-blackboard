#pragma once
#include <vector>
#include <cstddef>
#include <fstream>

#include "Figure.h"

class Blackboard {
public:
    Blackboard(size_t width, size_t height);

    void setWidth(size_t value);

    size_t getWidth() const;

    void setHeight(size_t value);

    size_t getHeight() const;

    static size_t generateFigureId();

private:
    size_t width;
    size_t height;
    std::vector<std::vector<char> > grid;
    std::vector<std::unique_ptr<Figure> > currentFigures;
    static size_t nextFigureId;
};
