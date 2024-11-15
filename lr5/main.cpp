#include <iostream>
#include "../include/CustomQueue.h"
#include "../include/MemoryPool.h"

// Структура для демонстрации работы с более сложными типами
struct MyStruct {
    int a;
    std::string b;

    MyStruct(int x, std::string str) : a(x), b(str) {}

    bool operator==(const MyStruct& other) const {
        return a == other.a && b == other.b;
    }
};

template class CustomQueue<int>;           // Для int
template class CustomQueue<MyStruct>;      // Для MyStruct

int main() {
    MemoryPool pool;

    // Демонстрация работы с простыми типами данных (int)
    CustomQueue<int> queue_int(&pool);
    queue_int.enqueue(10);
    queue_int.enqueue(20);
    queue_int.enqueue(30);

    std::cout << "Elements in int queue: ";
    for (auto it = queue_int.begin(); it != queue_int.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Демонстрация работы с более сложными типами данных (структура)
    CustomQueue<MyStruct> queue_struct(&pool);
    queue_struct.enqueue(MyStruct(1, "First"));
    queue_struct.enqueue(MyStruct(2, "Second"));
    queue_struct.enqueue(MyStruct(3, "Third"));

    std::cout << "Elements in struct queue: ";
    for (auto it = queue_struct.begin(); it != queue_struct.end(); ++it) {
        std::cout << "(" << it->a << ", " << it->b << ") ";
    }
    std::cout << std::endl;

    return 0;
}