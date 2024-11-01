#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <memory>
#include "point.h"
#include <cmath>

template<typename T>
class Figure {
public:
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    virtual std::vector<Point<T>> vertices() const = 0; // Возвращает вектор вершин
    virtual double area() const = 0; // Возвращает площадь фигуры
    virtual Point<T> center() const = 0; // Возвращает геометрический центр
    virtual ~Figure() = default;

    // Оператор приведения к типу double (площадь)
    operator double() const {
        return area();
    }

    // Операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.read(is);
        return is;
    }

    // Оператор присваивания
    virtual Figure& operator=(const Figure& other) {
        if (this != &other) {
        }
        return *this;
    }

    // Оператор сравнения
    virtual bool operator==(const Figure& other) const = 0; // Оператор сравнения позволяет сравнивать два объекта на равенство

    virtual void print(std::ostream& os) const = 0; // Вывод информации о фигуре
    virtual void read(std::istream& is) = 0; // Чтение информации о фигуре
};

#endif 