// CustomQueue.cpp
#include "../include/CustomQueue.h"

// Реализация методов шаблонного класса
template <typename T>
CustomQueue<T>::CustomQueue(std::pmr::memory_resource* mr)
    : data_(allocator_type(mr)) {}

template <typename T>
void CustomQueue<T>::enqueue(const T& value) {
    data_.push_back(value);
}

template <typename T>
void CustomQueue<T>::dequeue() {
    if (!data_.empty()) {
        data_.pop_front();
    }
}

template <typename T>
size_t CustomQueue<T>::size() const {
    return data_.size();  // Используем метод size() контейнера std::deque
}

template <typename T>
T& CustomQueue<T>::front() {
    return data_.front();
}

template <typename T>
const T& CustomQueue<T>::front() const {
    return data_.front();
}

template <typename T>
bool CustomQueue<T>::empty() const {
    return data_.empty();
}

template <typename T>
CustomQueue<T>::Iterator::Iterator(typename std::deque<T, allocator_type>::iterator iter)
    : iter_(iter) {}

template <typename T>
typename CustomQueue<T>::Iterator::reference CustomQueue<T>::Iterator::operator*() const {
    return *iter_;
}

template <typename T>
typename CustomQueue<T>::Iterator::pointer CustomQueue<T>::Iterator::operator->() const {
    return &(*iter_);
}

template <typename T>
typename CustomQueue<T>::Iterator& CustomQueue<T>::Iterator::operator++() {
    ++iter_;
    return *this;
}

template <typename T>
typename CustomQueue<T>::Iterator CustomQueue<T>::Iterator::operator++(int) {
    Iterator tmp = *this;
    ++iter_;
    return tmp;
}

template <typename T>
bool CustomQueue<T>::Iterator::operator==(const Iterator& other) const {
    return iter_ == other.iter_;
}

template <typename T>
bool CustomQueue<T>::Iterator::operator!=(const Iterator& other) const {
    return iter_ != other.iter_;
}

template <typename T>
typename CustomQueue<T>::Iterator CustomQueue<T>::begin() {
    return Iterator(data_.begin());
}

template <typename T>
typename CustomQueue<T>::Iterator CustomQueue<T>::end() {
    return Iterator(data_.end());
}

// Определение структуры MyStruct
struct MyStruct {
    int a;
    std::string b;

    MyStruct(int x, std::string str) : a(x), b(str) {}

    bool operator==(const MyStruct& other) const {
        return a == other.a && b == other.b;
    }
};

// Явное инстанцирование шаблонов для типов, которые вы используете
template class CustomQueue<int>;           // Для int
template class CustomQueue<MyStruct>;      // Для MyStruct