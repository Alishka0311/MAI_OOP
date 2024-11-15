#include <gtest/gtest.h>
#include "../include/CustomQueue.h"
#include "../include/MemoryPool.h"

// Тест для работы с простыми типами данных (int)
TEST(CustomQueueTest, SimpleTypes) {
    MemoryPool pool;
    CustomQueue<int> queue(&pool); 

    EXPECT_TRUE(queue.empty());

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.size(), 3);  

    EXPECT_EQ(queue.front(), 1); 
    queue.dequeue();
    EXPECT_EQ(queue.front(), 2); 
    EXPECT_EQ(queue.size(), 2);  

    queue.dequeue();
    queue.dequeue();
    EXPECT_TRUE(queue.empty()); 
}

// Тест для работы с комплексными типами данных
struct MyStruct {
    int a;
    std::string b;

    bool operator==(const MyStruct& other) const {
        return a == other.a && b == other.b;
    }
};

TEST(CustomQueueTest, ComplexTypes) {
    MemoryPool pool;
    CustomQueue<MyStruct> queue(&pool); 

    MyStruct s1 = {1, "Hello"};
    MyStruct s2 = {2, "World"};
    MyStruct s3 = {3, "Foo"};

    queue.enqueue(s1);
    queue.enqueue(s2);
    queue.enqueue(s3);

    EXPECT_EQ(queue.size(), 3); 
    EXPECT_EQ(queue.front(), s1); 

    queue.dequeue();
    EXPECT_EQ(queue.front(), s2); 

    queue.dequeue();
    EXPECT_EQ(queue.front(), s3); 
    EXPECT_EQ(queue.size(), 1);  

    queue.dequeue();
    EXPECT_TRUE(queue.empty()); 
}

// Тест для итераторов
TEST(CustomQueueTest, IteratorTest) {
    MemoryPool pool;
    CustomQueue<int> queue(&pool); 

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    auto it = queue.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2); 
    ++it;
    EXPECT_EQ(*it, 3); 
    ++it;
    EXPECT_EQ(it, queue.end()); 

    auto it2 = queue.begin();
    EXPECT_NE(it, it2);

    ++it2;
    ++it2;
    ++it2;
    EXPECT_EQ(it2, it);
}

// Тест для контейнера
TEST(CustomQueueTest, ContainerTest) {
    MemoryPool pool;
    CustomQueue<int> queue(&pool); 

    EXPECT_TRUE(queue.empty()); 

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    EXPECT_FALSE(queue.empty()); 
    EXPECT_EQ(queue.size(), 3);  

    auto it = queue.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    EXPECT_TRUE(queue.empty()); 
}

// Дополнительные тесты для итераторов
TEST(CustomQueueTest, IteratorOperations) {
    MemoryPool pool;
    CustomQueue<int> queue(&pool); 

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    auto it = queue.begin();
    EXPECT_EQ(*it, 1);

    auto it2 = it++;
    EXPECT_EQ(*it2, 1);
    EXPECT_EQ(*it, 2);

    auto it3 = queue.begin();
    EXPECT_NE(it, it3);
    ++it3;
    EXPECT_EQ(it, it3);
}

// Тест для проверки работы с пустой очередью
TEST(CustomQueueTest, EmptyQueueOperations) {
    MemoryPool pool;
    CustomQueue<int> queue(&pool);

    EXPECT_TRUE(queue.empty()); 
    EXPECT_EQ(queue.size(), 0); 

    auto it = queue.begin();
    EXPECT_EQ(it, queue.end());

    queue.dequeue();
    EXPECT_TRUE(queue.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}