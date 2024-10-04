#ifndef TWELVE_H
#define TWELVE_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <algorithm>

class Twelve {
public:
    // Конструктор по умолчанию
    Twelve();

    // Конструктор с параметром размера и начальным значением
    Twelve(const size_t &n, unsigned char t = '0');

    // Конструктор с initializer_list
    Twelve(const std::initializer_list<unsigned char> &t);

    // Конструктор с std::string
    Twelve(const std::string &t);

    // Конструктор копирования
    Twelve(const Twelve &other);

    // Конструктор перемещения
    Twelve(Twelve &&other) noexcept;

    // Деструктор
    ~Twelve() noexcept;

    // Оператор копирующего присваивания
    Twelve& operator=(const Twelve &other);

    // Оператор перемещающего присваивания
    Twelve& operator=(Twelve &&other) noexcept;

    // Оператор сложения
    Twelve operator+(const Twelve &other) const;

    // Оператор вычитания
    Twelve operator-(const Twelve &other) const;

    // Оператор сложения с присваиванием
    Twelve& operator+=(const Twelve &other);

    // Оператор вычитания с присваиванием
    Twelve& operator-=(const Twelve &other);

    // Оператор проверки на равенство
    bool operator==(const Twelve &other) const;

    // Оператор проверки на неравенство
    bool operator!=(const Twelve &other) const;

    // Оператор проверки на "меньше"
    bool operator<(const Twelve &other) const;

    // Оператор проверки на "больше"
    bool operator>(const Twelve &other) const;

    // Оператор проверки на "меньше или равно"
    bool operator<=(const Twelve &other) const;

    // Оператор проверки на "больше или равно"
    bool operator>=(const Twelve &other) const;

    // Метод для вывода двенадцатеричного числа
    std::ostream &print(std::ostream &os) const;

    // Метод для получения размера числа
    size_t getSize() const;

    // Метод для получения данных числа
    unsigned char* getData() const;

private:
    size_t _size;
    unsigned char *_array;

    static bool isTwelveBase(char M) {
        return (M >= '0' && M <= '9') || (M >= 'A' && M <= 'B');
    }//явл ли допустимой

    static int charToDigit(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'A' && c <= 'B') return c - 'A' + 10;
        throw std::logic_error("Invalid character");
    }

    static char digitToChar(int digit) {
        if (digit >= 0 && digit <= 9) return digit + '0';
        if (digit >= 10 && digit <= 11) return digit - 10 + 'A';
        throw std::logic_error("Invalid digit");
    }
};

#endif // TWELVE_H