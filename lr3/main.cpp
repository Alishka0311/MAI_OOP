#include <iostream>
#include <array>
#include <memory>
#include "array.h"  
#include "square.h"  
#include "rectangle.h"
#include "trap.h"

// Функция для ввода фигуры и добавления её в массив по индексу
void inputFigure(Array& arr, int index) {
    int figureType;
    std::cout << "Введите тип фигуры (1 - Квадрат, 2 - Прямоугольник, 3 - Трапеция): ";
    std::cin >> figureType;

    switch (figureType) {
        case 1: {
            Square* square = new Square();
            square->read(std::cin); // Ввод данных для квадрата
            arr.add(index, square); // Добавление в массив
            break;
        }
        case 2: {
            Rectangle* rectangle = new Rectangle();
            rectangle->read(std::cin); // Ввод данных для прямоугольника
            arr.add(index, rectangle); // Добавление в массив
            break;
        }
        case 3: {
            Trapeze* trapeze = new Trapeze();
            trapeze->read(std::cin); // Ввод данных для трапеции
            arr.add(index, trapeze); // Добавление в массив
            break;
        }
        default:
            std::cout << "Неверный тип фигуры!" << std::endl;
            break;
    }
}

int main() {
    Array figures(10); // Создаем массив на 10 фигур
    int figureCount;

    std::cout << "Сколько фигур вы хотите ввести (максимум 10)? ";
    std::cin >> figureCount;

    if (figureCount > 10 || figureCount < 1) {
        std::cout << "Некорректное количество фигур. Уменьшите или увеличьте количество фигур (от 1 до 10)." << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    // Ввод фигур в массив
    for (int i = 0; i < figureCount; i++) {
        inputFigure(figures, i);
    }

    // Вывод информации о фигурах
    std::cout << "\nИнформация о фигурах:" << std::endl;
    for (int i = 0; i < figureCount; i++) {
        Figure* fig = figures[i];
        if (fig) {
            std::cout << "Фигура " << (i + 1) << ":" << std::endl;
            auto center = fig->center();
            std::cout << "Геометрический центр: (" << center.first << ", " << center.second << ")" << std::endl;
            std::cout << "Площадь: " << static_cast<double>(*fig) << std::endl;

            // Выводим вершины фигуры
            std::cout << "Вершины: ";
            for (const auto& vertex : fig->vertices()) {
                std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            std::cout << std::endl;

            fig->print(std::cout); // Вывод дополнительной информации о фигуре через метод print()
            std::cout << std::endl;
        }
    }

    // Вывод общей площади фигур в массиве
    std::cout << "\nОбщая площадь всех фигур: " << figures.total_area() << std::endl;

    // Удаление фигуры по индексу
    int indexToDelete;
    std::cout << "Введите индекс фигуры для удаления (0-" << (figureCount - 1) << "): ";
    std::cin >> indexToDelete;

    if (indexToDelete >= 0 && indexToDelete < figureCount) {
        figures.del_figure(indexToDelete);
    } else {
        std::cout << "Неверный индекс!" << std::endl;
    }

    // Вывод массива после удаления фигуры
    std::cout << "\nМассив после удаления фигуры:\n";
    for (int i = 0; i < figureCount; i++) {
        Figure* fig = figures[i];
        if (fig) {
            std::cout << "Фигура " << (i + 1) << ":" << std::endl;
            auto center = fig->center();
            std::cout << "Геометрический центр: (" << center.first << ", " << center.second << ")" << std::endl;
            std::cout << "Площадь: " << static_cast<double>(*fig) << std::endl;

            // Выводим вершины фигуры
            std::cout << "Вершины: ";
            for (const auto& vertex : fig->vertices()) {
                std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
            }
            std::cout << std::endl;

            fig->print(std::cout);
            std::cout << std::endl;
        }
    }

    return 0;
}
