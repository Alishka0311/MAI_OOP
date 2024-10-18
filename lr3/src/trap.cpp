#include "trap.h"

// Конструктор по умолчанию
Trapeze::Trapeze() : base1(1.0), base2(1.0), height(1.0) {} // Установим значения по умолчанию

// Конструктор с основанием и высотой
Trapeze::Trapeze(double base1, double base2, double height) 
    : base1(base1), base2(base2), height(height) {}

// Конструктор копирования
Trapeze::Trapeze(const Trapeze& other) 
    : base1(other.base1), base2(other.base2), height(other.height) {}

// Конструктор перемещения
Trapeze::Trapeze(Trapeze&& other) noexcept 
    : base1(other.base1), base2(other.base2), height(other.height) {
    other.base1 = 0;  // Обнуляем перемещаемые значения
    other.base2 = 0;
    other.height = 0;
}
std::vector<std::pair<double, double>> Trapeze::vertices() const {
    std::vector<std::pair<double, double>> verts;
    verts.emplace_back(0.0, 0.0);                        // Левый нижний угол
    verts.emplace_back(base1, 0.0);                    // Правый нижний угол
    verts.emplace_back((base1 - base2) / 2.0, height); // Левый верхний угол
    verts.emplace_back((base1 + base2) / 2.0, height); // Правый верхний угол
    return verts;
}

// Оператор копирования
Trapeze& Trapeze::operator=(const Trapeze& other) {
    if (this != &other) {  // Проверка на самоприсваивание
        base1 = other.base1;
        base2 = other.base2;
        height = other.height;
    }
    return *this;
}

// Оператор перемещения
Trapeze& Trapeze::operator=(Trapeze&& other) noexcept {
    if (this != &other) {  // Проверка на самоприсваивание
        base1 = other.base1;
        base2 = other.base2;
        height = other.height;
        other.base1 = 0;  // Обнуляем перемещаемые значения
        other.base2 = 0;
        other.height = 0;
    }
    return *this;
}

// Площадь трапеции
Trapeze::operator double() const {
    return ((base1 + base2) / 2) * height; // Формула для площади трапеции
}

// Геометрический центр
std::pair<double, double> Trapeze::center() const {
    return { (base1 + base2) / 2.0, height / 2.0 }; // Центр трапеции
}


// Оператор присваивания от базового класса
Figure& Trapeze::operator=(const Figure& other) {
    const Trapeze* ptr = dynamic_cast<const Trapeze*>(&other);
    if (ptr) {
        *this = *ptr;  // Используем наш оператор присваивания
    }
    return *this;
}
// Оператор сравнения
bool Trapeze::operator==(const Figure& other) const {
    const Trapeze* ptr = dynamic_cast<const Trapeze*>(&other);
    if (ptr) {
        return base1 == ptr->base1 && base2 == ptr->base2 && height == ptr->height;  // Сравниваем параметры
    }
    return false;
}

// Вывод информации о фигуре
void Trapeze::print(std::ostream &os) const {
    os << "Trapeze bases: " << base1 << ", " << base2 << ", height: " << height << "\nVertices: ";
    for (const auto& vertex : vertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << std::endl;
}

// Чтение информации о фигуре
void Trapeze::read(std::istream &is) {
    std::cout << "Enter base1, base2, and height of the trapeze:\n";
    is >> base1 >> base2 >> height; // Читаем основания и высоту
}
