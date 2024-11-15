#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <memory_resource>
#include <vector>
#include <queue>

class MemoryPool : public std::pmr::memory_resource {
public:
    MemoryPool();
    ~MemoryPool();

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;//выдел памяти
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;//освобожд памяти
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;//сравнение ресурсов пам

private:
    std::vector<void*> allocated_blocks_;//выделенные блоки для очист при заверш
    std::queue<void*> free_blocks_;//освобожд блоков для переисп
};

#endif 
