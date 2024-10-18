#pragma once
#include "figure.h"
#include <array>
#include <utility>

class Trapeze : public Figure {
private:
    double base1; // Основание 1
    double base2; // Основание 2
    double height; // Высота

public:
    // Конструктор по умолчанию
    Trapeze();

    // Конструктор с основанием и высотой
    Trapeze(double base1, double base2, double height);


    // Конструктор копирования
    Trapeze(const Trapeze& other);

    // Конструктор перемещения
    Trapeze(Trapeze&& other) noexcept;

    // Оператор копирования
    Trapeze& operator=(const Trapeze& other);

    // Оператор перемещения
    Trapeze& operator=(Trapeze&& other) noexcept;

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
