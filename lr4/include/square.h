#ifndef SQUARE_H
#define SQUARE_H

#include "point.h"
#include "figure.h"
#include <cmath>

template<typename T>
class Square : public Figure<T> {
public:
    Square(Point<T> bottom_left = Point<T>(), T side_length = T())
        : _bottom_left(std::make_unique<Point<T>>(bottom_left)), _side_length(side_length) {}

    std::vector<Point<T>> vertices() const override {
        return {
            *_bottom_left,
            Point<T>(_bottom_left->x + _side_length, _bottom_left->y),
            Point<T>(_bottom_left->x + _side_length, _bottom_left->y + _side_length),
            Point<T>(_bottom_left->x, _bottom_left->y + _side_length)
        };
    }

    double area() const override {
        return _side_length * _side_length;
    }

    Point<T> center() const override {
        return Point<T>(_bottom_left->x + _side_length / 2, _bottom_left->y + _side_length / 2);
    }

    void print(std::ostream& os) const override {
        os << "Square: Bottom Left = " << *_bottom_left << ", Side Length = " << _side_length;
    }

    void read(std::istream& is) override {
        is >> *_bottom_left >> _side_length;
    }

    // Оператор присваивания
    Square& operator=(const Square& other) {
        if (this != &other) {
            _bottom_left = std::make_unique<Point<T>>(*other._bottom_left);
            _side_length = other._side_length;
        }
        return *this;
    }

    // Оператор сравнения
    bool operator==(const Figure<T>& other) const override {
        const Square<T>* square = dynamic_cast<const Square<T>*>(&other);
        return square && *_bottom_left == *square->_bottom_left && _side_length == square->_side_length;
    }

private:
    std::unique_ptr<Point<T>> _bottom_left;
    T _side_length;
};

#endif  