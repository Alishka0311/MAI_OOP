#pragma once
#include <iostream>
#include <utility>

class Figure {
public:
    virtual operator double() const = 0; // Площадь
    virtual std::pair<double, double> center() const = 0; // Геометрический центр
    virtual ~Figure() = default;// Виртуальный деструктор по умолчанию

    virtual Figure& operator=(const Figure& other){// Оператор присваивания позволяет копировать состояние одного объекта в другой объект того же класса.
        return *this;
    }; 
    virtual bool operator==(const Figure& other) const = 0; // Оператор сравнения позволяет сравнивать два объекта на равенство

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure) {
        figure.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& figure) {
        figure.read(is);
        return is;
    }

    virtual void print(std::ostream &os) const = 0; // Вывод информации о фигуре
    virtual void read(std::istream &is) = 0; // Чтение информации о фигуре
};
