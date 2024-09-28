#pragma once


class Figure {
public:
    virtual ~Figure() = default;

    static size_t id;
    double x;
    double y;

    Figure(const double y, const double x) : x(x), y(y) {}

    virtual void draw();

private:
    static size_t generateId() {
        static size_t currentId = 0;
        return currentId++;
    }
};
