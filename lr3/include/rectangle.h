#pragma once
#include "figure.h"
#include <array>
#include <utility>
#include <iostream>
#include <vector>

class Rectangle : public Figure {
private:
    double width; // Ширина прямоугольника
    double height; // Высота прямоугольника

public:
    // Конструктор по умолчанию
    Rectangle();

    // Конструктор с параметрами
    Rectangle(double width, double height);//высота ширина
    // Метод для получения вершин прямоугольника
    std::vector<std::pair<double, double>> vertices() const override;
    // Конструктор копирования
    Rectangle(const Rectangle& other);

    // Конструктор перемещения
    Rectangle(Rectangle&& other) noexcept;//Конструктор перемещения принимает rvalue-ссылку на другой объект того же класса

    // Оператор копирования
    Rectangle& operator=(const Rectangle& other);

    // Оператор перемещения
    Rectangle& operator=(Rectangle&& other) noexcept;

    // Площадь
    operator double() const override;//метод-преобразование площади фигуры в тип double

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
