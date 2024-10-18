#include <iostream>
#include <array>
#include <memory>
#include "array.h"  
#include "square.h"  
#include "rectangle.h"
#include "trap.h"

void inputFigure(Array& arr, int index) {
    int figureType;
    std::cout << "Введите тип фигуры (1 - Квадрат, 2 - Прямоугольник, 3 - Трапеция): ";
    std::cin >> figureType;

    switch (figureType) {
        case 1: {
            Square* square = new Square();
            square->read(std::cin); // Ввод данных
            arr.add(index, square); // Сохранение в массив
            break;
        }
        case 2: {
            Rectangle* rectangle = new Rectangle();
            rectangle->read(std::cin); // Ввод данных
            arr.add(index, rectangle);
            break;
        }
        case 3: {
            Trapeze* trapeze = new Trapeze();
            trapeze->read(std::cin); // Ввод данных
            arr.add(index, trapeze);
            break;
        }
        default:
            std::cout << "Неверный тип фигуры!" << std::endl;
            break;
    }
}

int main() {
    Array figures(10); // Массив на 10 фигур
    int figureCount;

    std::cout << "Сколько фигур вы хотите ввести? ";
    std::cin >> figureCount;

    if (figureCount > 10) {
        std::cout << "Максимальное количество фигур: 10. Уменьшите количество фигур." << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    for (int i = 0; i < figureCount; i++) {
        inputFigure(figures, i);
    }

    std::cout << "\nИнформация о фигурах:" << std::endl;
    for (int i = 0; i < figureCount; i++) {
        Figure* fig = figures[i];
        if (fig) {
            std::cout << "Фигура " << (i + 1) << ":" << std::endl;
            auto center = fig->center();
            std::cout << "Геометрический центр: " << center.first << ", " << center.second << std::endl;
            std::cout << "Площадь: " << static_cast<double>(*fig) << std::endl; // Используем перегрузку оператора приведения
            fig->print(std::cout); // Вывод информации о фигуре
        }
    }

    std::cout << "\nОбщая площадь фигур: " << figures.total_area() << std::endl;

    // Пример удаления фигуры по индексу
    int indexToDelete;
    std::cout << "Введите индекс фигуры для удаления (0-" << (figureCount - 1) << "): ";
    std::cin >> indexToDelete;

    if (indexToDelete >= 0 && indexToDelete < figureCount) {
        figures.del_figure(indexToDelete);
    } else {
        std::cout << "Неверный индекс!" << std::endl;
    }

    std::cout << "\nПосле удаления фигуры:\n";
    for (int i = 0; i < figureCount; i++) {
        Figure* fig = figures[i];
        if (fig) {
            std::cout << "Фигура " << (i + 1) << ":" << std::endl;
            auto center = fig->center();
            std::cout << "Геометрический центр: " << center.first << ", " << center.second << std::endl;
            std::cout << "Площадь: " << static_cast<double>(*fig) << std::endl;
            fig->print(std::cout);
        }
    }

    return 0;
}
