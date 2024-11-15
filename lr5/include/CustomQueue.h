#ifndef CUSTOM_QUEUE_H
#define CUSTOM_QUEUE_H

#include <deque>
#include <memory_resource>
#include <iterator>

template <typename T>
class CustomQueue {
public:
    using allocator_type = std::pmr::polymorphic_allocator<T>;

    // Конструктор с памятью
    CustomQueue(std::pmr::memory_resource* mr = std::pmr::get_default_resource());// то есть принимает указатель на класс:, который представляет полиморфный ресурс памяти, если не было передано ничего, то указатель на стандартный ресурс памяти

    // Методы для работы с очередью
    void enqueue(const T& value);// добавляем эл в очередь(принимает конст ссылку на объект типа T)
    void dequeue();//удал элемент с начала очереди
    T& front();//возвращает ссылку на элемент типа T в начале очереди
    const T& front() const;//Метод возвращает константную ссылку на элемент типа T(например для чтения)
    bool empty() const;//пуста ли очередь?
    size_t size() const;

    // Итератор
    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;//перемещение по конт только вперед
        using value_type = T;//тип значений с кот-ыми будет работать итеатор 
        using difference_type = std::ptrdiff_t;//тип разности между двумя итераторами(целочисленный тип,кот-ый гарантированно может хранить разницу между любыми двумя указателями в памяти)
        using pointer = T*;//определяет тип указателя на объект, на который указывает итератор(для разыменования)
        using reference = T&;//тип ссылки на объект, на который указывает итератор

        Iterator(typename std::deque<T, allocator_type>::iterator iter);

        reference operator*() const;//Операция разыменования итератора, которая возвращает ссылку на текущий элемент, на который указывает итератор.
        pointer operator->() const;//как разыменование но с доступом через указатель

        Iterator& operator++();//передвижение итератора на след элемент(возвр сам итератор)
        Iterator operator++(int);//возвр копию итератора

        bool operator==(const Iterator& other) const;//сравнение двух итераторов
        bool operator!=(const Iterator& other) const;//сравнение двух итераторов на неравенство 

    private:
        typename std::deque<T, allocator_type>::iterator iter_;
    };

    Iterator begin();
    Iterator end();

private:
    std::deque<T, allocator_type> data_;
};

#endif // CUSTOM_QUEUE_H
