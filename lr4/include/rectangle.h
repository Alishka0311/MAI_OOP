#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"
#include "figure.h"
#include <cmath>

template<typename T>
class Rectangle : public Figure<T> {
public:
    Rectangle(Point<T> bottom_left = Point<T>(), T width = T(), T height = T())
        : _bottom_left(std::make_unique<Point<T>>(bottom_left)), _width(width), _height(height) {}

    std::vector<Point<T>> vertices() const override {
        return {
            *_bottom_left,
            Point<T>(_bottom_left->x + _width, _bottom_left->y),
            Point<T>(_bottom_left->x + _width, _bottom_left->y + _height),
            Point<T>(_bottom_left->x, _bottom_left->y + _height)
        };
    }

    double area() const override {
        return _width * _height;
    }

    Point<T> center() const override {
        return Point<T>(_bottom_left->x + _width / 2, _bottom_left->y + _height / 2);
    }

    void print(std::ostream& os) const override {
        os << "Rectangle: Bottom Left = " << *_bottom_left << ", Width = " << _width << ", Height = " << _height;
    }

    void read(std::istream& is) override {
        is >> *_bottom_left >> _width >> _height;
    }

    // Оператор присваивания
    Rectangle& operator=(const Rectangle& other) {
        if (this != &other) {
            _bottom_left = std::make_unique<Point<T>>(*other._bottom_left);
            _width = other._width;
            _height = other._height;
        }
        return *this;
    }

    // Оператор сравнения
    bool operator==(const Figure<T>& other) const override {
        const Rectangle<T>* rectangle = dynamic_cast<const Rectangle<T>*>(&other);
        return rectangle && *_bottom_left == *rectangle->_bottom_left &&
               _width == rectangle->_width && _height == rectangle->_height;
    }

private:
    std::unique_ptr<Point<T>> _bottom_left;
    T _width;
    T _height;
};

#endif  