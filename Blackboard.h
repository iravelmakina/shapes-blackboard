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

    void draw();

    void list() const;

    static void shapes();

    void add(int typeId, int x, int y, int param1, int param2 = 0, int param3 = 0, int param4 = 0);

    void undo();

    void clear();

private:
    size_t width;
    size_t height;
    std::vector<std::vector<char> > grid;
    std::vector<std::unique_ptr<Figure> > currentFigures;
    static size_t nextFigureId;

    void print() const;

    void resetGrid();

    static std::unique_ptr<Figure> createFigure(int typeId, int x, int y, int param1, int param2, int param3,
                                                int param4);

    bool canPlaceFigure(int x, int y, int param1, int param2, int param3, int param4, int typeId) const;

    bool isDuplicateFigure(const std::unique_ptr<Figure> &newFigure) const;

    void parseAndAddFigure(std::istringstream &iss, int typeId);
};
