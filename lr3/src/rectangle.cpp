#include "rectangle.h"

// Конструктор по умолчанию
Rectangle::Rectangle() : width(1.0), height(1.0) {}

// Конструктор с параметрами
Rectangle::Rectangle(double width, double height) : width(width), height(height) {}

// Конструктор копирования
Rectangle::Rectangle(const Rectangle& other) 
    : width(other.width), height(other.height) {}

// Конструктор перемещения
Rectangle::Rectangle(Rectangle&& other) noexcept 
    : width(other.width), height(other.height) {
    other.width = 0;  // Обнуляем перемещаемые значения
    other.height = 0;
}

// Оператор копирования
Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {  // Проверка на самоприсваивание
        width = other.width;
        height = other.height;
    }
    return *this;
}
// Метод для получения вершин прямоугольника
std::vector<std::pair<double, double>> Rectangle::vertices() const {
    return {
        {0, 0},
        {width, 0},
        {width, height},
        {0, height}
    };
}

// Оператор перемещения
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {  // Проверка на самоприсваивание
        width = other.width;
        height = other.height;
        other.width = 0;  // Обнуляем перемещаемые значения
        other.height = 0;
    }
    return *this;
}

// Площадь
Rectangle::operator double() const {
    return width * height; // Площадь прямоугольника
}

// Геометрический центр
std::pair<double, double> Rectangle::center() const {
    return { width / 2.0, height / 2.0 }; // Центр прямоугольника
}


// Оператор присваивания от базового класса
Figure& Rectangle::operator=(const Figure& other) {
    const Rectangle* ptr = dynamic_cast<const Rectangle*>(&other);//dynamic_cast пытается привести указатель на базовый класс Figure к указателю на производный класс Rectangle.
    if (ptr) {
        *this = *ptr;  // Используем наш оператор копирования, если other действительно является объектом типа Rectangle
    }
    return *this;
}

// Оператор сравнения
bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* ptr = dynamic_cast<const Rectangle*>(&other);
    if (ptr) {
        return width == ptr->width && height == ptr->height; // Сравниваем параметры
    }
    return false;
}

// Вывод информации о фигуре
void Rectangle::print(std::ostream& os) const {
    os << "Rectangle width: " << width << ", height: " << height << "\nVertices: ";
    for (const auto& vertex : vertices()) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
    os << std::endl;
}


// Чтение информации о фигуре
void Rectangle::read(std::istream &is) {
    std::cout << "Enter width and height of the rectangle:\n";
    is >> width >> height; // Читаем ширину и высоту
}
