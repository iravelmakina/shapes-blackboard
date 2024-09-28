#pragma once


class Figure {
public:
    virtual ~Figure() = default;

    Figure(const double y, const double x) : x(x), y(y) {}

    void setId(size_t input);

    size_t getId() const;

    void setX(double input);

    double getX() const;

    void setY(double input);

    double getY() const;

    virtual void draw();

private:
    size_t id;
    double x;
    double y;
};
