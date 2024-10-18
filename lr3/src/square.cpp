#include "square.h"

// Конструктор по умолчанию
Square::Square() : side(1.0) {} // Установим сторону по умолчанию 1.0

// Конструктор по стороне
Square::Square(double side) : side(side) {}

// Конструктор копирования
Square::Square(const Square& other) : side(other.side) {}

// Конструктор перемещения
Square::Square(Square&& other) noexcept : side(other.side) {
    other.side = 0; // Обнуляем значение перемещаемого объекта
}

// Оператор копирования
Square& Square::operator=(const Square& other) {
    if (this != &other) {  // Проверка на самоприсваивание
        side = other.side;
    }
    return *this;
}

// Оператор перемещения
Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {  // Проверка на самоприсваивание
        side = other.side;
        other.side = 0; // Обнуляем значение перемещаемого объекта
    }
    return *this;
}

// Площадь
Square::operator double() const {
    return side * side;
}

// Геометрический центр
std::pair<double, double> Square::center() const {
    return { side / 2.0, side / 2.0 }; // Центр квадрата
}


// Оператор присваивания от базового класса
Figure& Square::operator=(const Figure& other) {
    const Square* ptr = dynamic_cast<const Square*>(&other);
    if (ptr) {
        *this = *ptr;  // Используем наш оператор присваивания
    }
    return *this;
}
// Метод для получения вершин квадрата
std::vector<std::pair<double, double>> Square::vertices() const {
    return {
        {0, 0},
        {side, 0},
        {side, side},
        {0, side}
    };
}

// Оператор сравнения
bool Square::operator==(const Figure& other) const {
    const Square* ptr = dynamic_cast<const Square*>(&other);
    if (ptr) {
        return side == ptr->side;  // Сравниваем стороны
    }
    return false;
}

// Вывод информации о фигуре
void Square::print(std::ostream &os) const {
    os << "Square side: " << side << "\nVertices: ";
    for (const auto& vertex : vertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << std::endl;
}
// Чтение информации о фигуре
void Square::read(std::istream &is) {
    std::cout << "Enter the side length of the square:\n";
    is >> side; // Читаем длину стороны
}
