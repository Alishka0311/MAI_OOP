#include <iostream>
#include <memory>
#include "include/point.h"
#include "include/figure.h"
#include "include/rectangle.h"  
#include "include/square.h"     
#include "include/trap.h"      
#include "include/array.h"      

// Функция для ввода фигуры
std::shared_ptr<Figure<double>> createFigure() {
    std::string type;
    std::cout << "Введите тип фигуры (rectangle, square, trapezoid): ";
    std::cin >> type;

    if (type == "rectangle") {
        double width, height;
        std::cout << "Введите ширину и высоту прямоугольника: ";
        std::cin >> width >> height;
        return std::make_shared<Rectangle<double>>(width, height);
    } else if (type == "square") {
        double side;
        std::cout << "Введите сторону квадрата: ";
        std::cin >> side;
        return std::make_shared<Square<double>>(side);
    } else if (type == "trapezoid") {
        double a, b, height;
        std::cout << "Введите основание a, основание b и высоту трапеции: ";
        std::cin >> a >> b >> height;
        return std::make_shared<Trapezoid<double>>(a, b, height);
    } else {
        std::cerr << "Неизвестный тип фигуры!" << std::endl;
        return nullptr;
    }
}

// Основная функция
int main() {
    Array<Figure<double>> figures; // Динамический массив для хранения фигур

    char more;
    do {
        auto figure = createFigure();
        if (figure) {
            figures.push_back(figure);
            std::cout << "Добавлена фигура. Текущий размер массива: " << figures.size() << std::endl;
        }
        std::cout << "Добавить еще фигуру? (y/n): ";
        std::cin >> more;
    } while (more == 'y');

    // Вывод информации о фигурах
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ":" << std::endl;
        std::cout << "Площадь: " << figures[i]->area() << std::endl;

        Point<double> center = figures[i]->center();
        std::cout << "Геометрический центр: (" << center.getX() << ", " << center.getY() << ")" << std::endl;
        figures[i]->print(std::cout);  
    }

    // Общая площадь фигур
    double totalArea = figures.totalArea();
    std::cout << "Общая площадь фигур: " << totalArea << std::endl;

    // Удаление фигуры по индексу
    size_t indexToRemove;
    std::cout << "Введите индекс фигуры для удаления (0-" << figures.size() - 1 << "): ";
    std::cin >> indexToRemove;

    // Проверка корректности индекса перед удалением
    if (indexToRemove < figures.size()) {
        figures.remove(indexToRemove);
        std::cout << "Фигура " << indexToRemove + 1 << " удалена." << std::endl;
    } else {
        std::cerr << "Некорректный индекс!" << std::endl;
    }

    return 0;
}
