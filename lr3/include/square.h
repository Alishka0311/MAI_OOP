#pragma once
#include "figure.h"
#include <array>
#include <vector>

class Square : public Figure {
private:
    double side;
public:
    // Конструктор по умолчанию
    Square();

    // Конструктор по стороне
    Square(double side);
    //метод для получения вершин квадрата
    std::vector<std::pair<double, double>> vertices() const override;
    // Конструктор копирования
    Square(const Square& other);

    // Конструктор перемещения
    Square(Square&& other) noexcept;

    // Оператор копирования
    Square& operator=(const Square& other);

    // Оператор перемещения
    Square& operator=(Square&& other) noexcept;

    // Площадь
    operator double() const override;

    // Геометрический центр
    std::pair<double, double> center() const override;

    // Оператор присваивания от базового класса
    Figure& operator=(const Figure& other) override;

    // Оператор сравнения
    bool operator==(const Figure& other) const override;

    // Вывод информации о фигуре
    void print(std::ostream &os) const override;

    // Чтение информации о фигуре
    void read(std::istream &is) override;
};


