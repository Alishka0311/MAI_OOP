#include <iostream>
#include "include/Twelve.h"

// Пример использования класса Twelve
void exampleUsage() {
    try {
        // Создание объектов Twelve
        Twelve num1("123");
        Twelve num2("456");

        // Вывод чисел
        std::cout << "num1: ";
        num1.print(std::cout);
        std::cout << std::endl;

        std::cout << "num2: ";
        num2.print(std::cout);
        std::cout << std::endl;

        // Сложение чисел
        Twelve sum = num1.add(num2);
        std::cout << "Sum: ";
        sum.print(std::cout);
        std::cout << std::endl;

        // Вычитание чисел
        Twelve diff = num1.subtract(num2);
        std::cout << "Difference: ";
        diff.print(std::cout);
        std::cout << std::endl;

        // Сравнение чисел
        if (num1.equals(num2)) {
            std::cout << "num1 is equal to num2" << std::endl;
        } else if (num1.lessThan(num2)) {
            std::cout << "num1 is less than num2" << std::endl;
        } else {
            std::cout << "num1 is greater than num2" << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

// Главная функция
int main() {
    exampleUsage();

    return 0;
}