#include "../include/MemoryPool.h"
#include <cassert>

// Конструктор
MemoryPool::MemoryPool() = default;

// Деструктор очищает неосвобожденную память
MemoryPool::~MemoryPool() {
    for (void* block : allocated_blocks_) {
        ::operator delete(block);
    }
}

// Реализация метода выделения памяти
void* MemoryPool::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (!free_blocks_.empty()) {//если есть освобожд блоки исп их
        void* block = free_blocks_.front();
        free_blocks_.pop();
        return block;
    }

    void* block = ::operator new(bytes);//иначе выдел новый блок
    allocated_blocks_.push_back(block);
    return block;
}

void MemoryPool::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    free_blocks_.push(p);
}

bool MemoryPool::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
