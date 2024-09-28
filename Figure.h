#pragma once


class Figure {
public:
    virtual ~Figure() = default;

    Figure(size_t id, double x, double y);

    void setId(size_t value);

    size_t getId() const;

    void setX(double value);

    double getX() const;

    void setY(double value);

    double getY() const;

    virtual void draw();

private:
    size_t id = 0;
    double x;
    double y;
};
