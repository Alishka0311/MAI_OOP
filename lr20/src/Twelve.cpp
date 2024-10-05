#include <iostream>
#include <initializer_list>
#include "../include/Twelve.h"

// Конструктор по умолчанию
Twelve::Twelve() : _size(1), _array(new unsigned char[1]) {//список инициализации членов класса
    _array[0] = '0';
}

// Конструктор с параметром размера и начальным значением
Twelve::Twelve(const size_t &n, unsigned char t) {
    if (!isTwelveBase(t)) throw std::logic_error("char should be in twelve-base system");//если не 12рич сс, то выброс исключение
    
    if (t == '0') {
        _array = new unsigned char[1]{'0'};//указатель на массив типа un... 
        _size = 1;//если t это 0, то просто выделяем память для 1 элемента и присваив ему значение 0
    } else {
        _array = new unsigned char[n];//выделяем память для n элементов
        for (size_t i = 0; i < n; i++) {//проходимя по массиву c помощью индекса i и записываем t
            _array[i] = t;
        }
        _size = n;
    }
}

// Конструктор с initializer_list(создание объекта и инициализация его начениями, переданными в виде списка)
Twelve::Twelve(const std::initializer_list<unsigned char> &t) {
    size_t leadingZeros = 0;//подсчет кол-ва ведущих нулей в списке инициализ
    bool countZeros = true;//нужно ли продолжать подсчет вед нулей?

    for (unsigned char A : t) { // Определяем количество ведущих нулей и проверяем символы
        if (!isTwelveBase(A)) throw std::logic_error("not twelve-base system");//проход по всем элементам списка инициализации
        if (countZeros && A == '0') {
            leadingZeros++;
        } else {
            countZeros = false;//подсчет ведущих нулей прекращается
        }
    }

    _size = t.size() - leadingZeros;//вычисление размера массива без вед нулей

    if (_size == 0) {
        _array = new unsigned char[1]{'0'};
        _size = 1;
    } else {
        _array = new unsigned char[_size];//выделяем память для size элементов
        int i = 0;
        for (auto it = t.end() - 1; it != t.begin() - 1 + leadingZeros; --it) { // Копируем символы без ведущих нулей
            _array[i++] = *it;//разыменование итератора
        }
    }
}

// Конструктор с std::string
Twelve::Twelve(const std::string &t) {
    size_t leadingZeros = 0;
    bool countZeros = true;

    for (size_t i = 0; i < t.size(); i++) {// Определяем количество ведущих нулей и проверяем символы
        if (!isTwelveBase(t[i])) throw std::logic_error("not twelve-base system");
        if (countZeros && t[i] == '0') {
            leadingZeros++;
        } else {
            countZeros = false;
        }
    }

    _size = t.size() - leadingZeros;

    if (_size == 0) {
        _array = new unsigned char[1]{'0'};
        _size = 1;
    } else {
        _array = new unsigned char[_size];
        for (size_t i = 0; i < _size; i++) {//проходим по символам строки в обр порядке до следующего символа после вед нуля
            _array[i] = t[t.size() - 1 - i];
        }
    }
}

// Конструктор копирования
Twelve::Twelve(const Twelve &other) {
    _size = other._size;//Переменной _size присваивается значение переменной _size другого объекта othe
    _array = new unsigned char[_size];// _array - указатель на выделенную память для массива

    for (size_t i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

// Конструктор перемещения
Twelve::Twelve(Twelve &&other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

// Деструктор
Twelve::~Twelve() noexcept {
    delete[] _array;
}

// Метод  сложения(возвращает новый объект)
Twelve Twelve::add(const Twelve &other) const {//ссылка на const объект
    size_t max_size = std::max(_size, other._size) + 1;//макс размер из двух массивов + перенос
    unsigned char *result_array = new unsigned char[max_size];//Выделяется память для массива result_array размером max_size элементов типа unsigned char
    size_t i = 0;//индекс для прохода по массивам
    int temp = 0;//хранит значение, которое переносится из текущего разряда в следующий

    while (i < _size || i < other._size || temp) {//пока не обработаны все эл массива и temp!=0
        int digit1 = 0;
        int digit2 = 0;

        if (i < _size) {
            digit1 = charToDigit(_array[i]);;//символ _array[i] преобразуем в цифру
        }

        if (i < other._size) {
            digit2 = charToDigit(other._array[i]);
        }

        int sum = digit1 + digit2 + temp;//сумммируем цифры текущ разряда и temp(перенос)
        result_array[i] = digitToChar(sum % 12);//результат суммы по модулю 12 преобр в символ и запис в массиве result_array
        temp = sum / 12;//целочисленное деление суммы

        ++i;//переход к след разряду
    }

    Twelve result;
    result._array = result_array;//указатель на массив result_array присваиваем члену _array результ объекта
    result._size = i;
    return result;
}

// Метод для вычитания
Twelve Twelve::subtract(const Twelve &other) const {
    if (other.greaterThan(*this))
        throw std::range_error("a - b < 0");//выбрас искл, чтобы предотвратить вычитание, приводящее к отриц результату

    size_t max_size = std::max(_size, other._size);//макс размер из двух массивов(размер рез массива)
    unsigned char *result_array = new unsigned char[max_size];//Выделяется память для массива result_array размером max_size элементов типа unsigned cha
    size_t i = 0;//индекс для прохода по массивам
    int borrow = 0;//заимствование при вычитании
// Выполняем вычитание с учетом заимствования
    while (i < _size) {//цикл продолжается, пока не будут обработаны все элементы массива _array
        int digit1 = charToDigit(_array[i]);//преобр символ в цифру
        int digit2 = (i < other._size) ? charToDigit(other._array[i]) : 0;

        int diff = digit1 - digit2 - borrow;//разность между цифрами текущего разряда и заимствованием borrow

        if (diff < 0) {
            diff += 12;// Заимствуем 12
            borrow = 1;
        } else {
            borrow = 0;
        }

        result_array[i] = digitToChar(diff);//результат разности преобразуем обратно в символ и сохр в массиве result_array
        ++i;
    }
 // Находим фактический размер числа, не удаляя все нули 
    size_t result_size = max_size;
    while (result_size > 1 && result_array[result_size - 1] == '0') {//цикл продолжается, пока result_size больше 1 и последний элемент массива result_array равен '0'
        --result_size;
    }
 // Создаем результат с правильным размером
    Twelve result;
    result._array = new unsigned char[result_size];
    result._size = result_size;
    // Копируем результат в объект результата
    for (size_t j = 0; j < result_size; ++j) {
        result._array[j] = result_array[j];
    }

    delete[] result_array; // Освобождаем временный массив
    return result;
}

// Метод для проверки на равенство
bool Twelve::equals(const Twelve &other) const {
    if (_size != other._size) {
        return false;
    }
    for (size_t i = 0; i < _size; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }
    return true;
}

// Метод для проверки на неравенство
bool Twelve::notEquals(const Twelve &other) const {
    return !equals(other);
}

// Метод для проверки на "меньше"
bool Twelve::lessThan(const Twelve &other) const {
    if (_size < other._size)
        return true;
    else if (_size > other._size)
        return false;
    if (_size == 0)//пусто объект не мржет быть меньше др объекта
        return false;

    size_t i = _size - 1;
    while (i > 0 && _array[i] == other._array[i])//проход по элементам массивов _array (текущего объекта) и other._array объекта other с конца до начала
        --i;
    return _array[i] < other._array[i];
}

// Метод для проверки на "больше"
bool Twelve::greaterThan(const Twelve &other) const {
    if (_size > other._size)
        return true;
    else if (_size < other._size)
        return false;
    if (_size == 0)
        return false;

    size_t i = _size - 1;
    while (i > 0 && _array[i] == other._array[i])
        --i;
    return _array[i] > other._array[i];
}

// Метод для проверки на "меньше или равно"
bool Twelve::lessThanOrEqual(const Twelve &other) const {
    return lessThan(other) || equals(other);
}

// Метод для проверки на "больше или равно"
bool Twelve::greaterThanOrEqual(const Twelve &other) const {
    return greaterThan(other) || equals(other);
}

// Метод для вывода двенадцатеричного числа
std::ostream &Twelve::print(std::ostream &os) const {
    for (size_t i = _size; i > 0; --i) {// проход по всем элементам массива _array (текущего объекта) с конца к началу
        os << _array[i - 1];// вывод в поток os
    }
    return os;// Возвращается ссылка на поток вывода os
}

// Метод для получения размера числа
size_t Twelve::getSize() const {
    return _size;
}

// Метод для получения данных числа
unsigned char* Twelve::getData() const {
    return _array;
}