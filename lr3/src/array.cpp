#include "array.h"
#include <stdexcept> // Для std::invalid_argument

// Конструктор по умолчанию
Array::Array() {
    _size = 5; // Начальный размер массива
    _figures = new Figure*[_size]; // Создаем массив указателей(Выделяет память для массива указателей на объекты типа Figure)
    for (int i = 0; i < _size; i++) {
        _figures[i] = nullptr; // Инициализируем указатели как nullptr
    }
}

// Конструктор с заданным размером
Array::Array(int size) {
    if (size <= 0) { // Проверка на неотрицательный размер
        throw std::invalid_argument("Размер массива должен быть положительным!");
    }
    _size = size;
    _figures = new Figure*[_size]; // Создаем массив указателей
    for (int i = 0; i < _size; i++) {
        _figures[i] = nullptr; // Инициализируем указатели как nullptr
    }
}

// Деструктор
Array::~Array() {
    for (int i = 0; i < _size; i++) {
        delete _figures[i]; // Удаляем каждую фигуру, если она существует
    }
    delete[] _figures; // освобождает память, выделенную для массива указателей _figures
}

// Удаление фигуры по индексу
void Array::del_figure(int i) {
    if (i < 0 || i >= _size) // Проверка на корректность индекса
        throw std::invalid_argument("Такого индекса нет в массиве!");
    delete _figures[i]; // Освобождаем память фигуры
    _figures[i] = nullptr; // Устанавливаем указатель в nullptr
}

// Добавление фигуры по индексу
void Array::add(int i, Figure* figure) {
    if (i < 0 || i >= _size) // Проверка на корректность индекса
        throw std::invalid_argument("Такого индекса нет в массиве!");
    delete _figures[i]; // Освобождаем память, если фигура уже существует
    _figures[i] = figure; // Сохраняем указатель на новую фигуру
}

// Вычисление общей площади
double Array::total_area() {
    double res = 0.0; // Переменная для хранения общей площади
    for (int i = 0; i < _size; i++) {
        if (_figures[i] != nullptr) // Проверка на существование фигуры
            res += (double)*_figures[i]; // Суммируем площади(Преобразует объект Figure, на который указывает _figures[i], в тип double с помощью оператора преобразования operator double().)
    }
    return res; // Возвращаем общую площадь
}

// Оператор доступа по индексу
Figure* Array::operator[](int i) const {
    if (i < 0 || i >= _size) // Проверка на корректность индекса
        throw std::invalid_argument("Такого индекса нет в массиве!");
    return _figures[i]; //Возвращает указатель на объект Figure, который хранится в массиве _figures по индексу i.
}
