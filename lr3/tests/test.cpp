  #include <gtest/gtest.h>
#include "array.h"
#include "rectangle.h"
#include "square.h"
#include "trap.h"

// Тест конструктора по умолчанию
TEST(ArrayTest, DefaultConstructor) {
    Array arr;
    EXPECT_EQ(arr.total_area(), 0.0);//метод total_area() объекта arr, который должен вернуть общую площадь всех фигур в массиве.
}

// Тест конструктора с заданным размером
TEST(ArrayTest, ConstructorWithSize) {
    Array arr(10);
    EXPECT_EQ(arr.total_area(), 0.0);
}

// Тест добавления фигуры
TEST(ArrayTest, AddFigure) {
    Array arr;
    Rectangle* rect = new Rectangle(5.0, 3.0);
    arr.add(0, rect);
    EXPECT_EQ(arr.total_area(), 15.0);
}

// Тест удаления фигуры
TEST(ArrayTest, DeleteFigure) {
    Array arr;
    Rectangle* rect = new Rectangle(5.0, 3.0);
    arr.add(0, rect);
    arr.del_figure(0);
    EXPECT_EQ(arr.total_area(), 0.0);
}

// Тест вычисления общей площади
TEST(ArrayTest, TotalArea) {
    Array arr;
    Rectangle* rect1 = new Rectangle(5.0, 3.0);
    Rectangle* rect2 = new Rectangle(4.0, 2.0);
    arr.add(0, rect1);
    arr.add(1, rect2);
    EXPECT_EQ(arr.total_area(), 23.0);
}

// Тест оператора доступа по индексу
TEST(ArrayTest, IndexOperator) {
    Array arr;
    Rectangle* rect = new Rectangle(5.0, 3.0);
    arr.add(0, rect);
    EXPECT_EQ(arr[0], rect);
}
// Тест конструктора по умолчанию
TEST(RectangleTest, DefaultConstructor) {
    Rectangle rect;
    EXPECT_EQ(rect.operator double(), 1.0);
}

// Тест конструктора с параметрами
TEST(RectangleTest, ParameterizedConstructor) {
    Rectangle rect(5.0, 3.0);
    EXPECT_EQ(rect.operator double(), 15.0);
}

// Тест конструктора копирования
TEST(RectangleTest, CopyConstructor) {
    Rectangle rect1(5.0, 3.0);
    Rectangle rect2(rect1);
    EXPECT_EQ(rect2.operator double(), 15.0);
}

// Тест оператора копирования
TEST(RectangleTest, CopyAssignmentOperator) {
    Rectangle rect1(5.0, 3.0);
    Rectangle rect2;
    rect2 = rect1;
    EXPECT_EQ(rect2.operator double(), 15.0);
}

 TEST(RectangleTest, EqualityOperator) {
    Rectangle rect1(5.0, 3.0);
    Rectangle rect2(5.0, 3.0);
    EXPECT_TRUE(rect1 == static_cast<const Figure&>(rect2));
}
// Тест конструктора по умолчанию
TEST(SquareTest, DefaultConstructor) {
    Square sq;
    EXPECT_EQ(sq.operator double(), 1.0);
}

// Тест конструктора с параметром
TEST(SquareTest, ParameterizedConstructor) {
    Square sq(5.0);
    EXPECT_EQ(sq.operator double(), 25.0);
}

// Тест конструктора копирования
TEST(SquareTest, CopyConstructor) {
    Square sq1(5.0);
    Square sq2(sq1);
    EXPECT_EQ(sq2.operator double(), 25.0);
}

// Тест оператора копирования
TEST(SquareTest, CopyAssignmentOperator) {
    Square sq1(5.0);
    Square sq2;
    sq2 = sq1;
    EXPECT_EQ(sq2.operator double(), 25.0);
}

TEST(SquareTest, EqualityOperator) {
    Square sq1(5.0);
    Square sq2(5.0);
    EXPECT_TRUE(sq1 == static_cast<const Figure&>(sq2));
}
// Тест конструктора по умолчанию
TEST(TrapezeTest, DefaultConstructor) {
    Trapeze trap;
    EXPECT_EQ(trap.operator double(), 1.0);
}

// Тест конструктора с параметрами
TEST(TrapezeTest, ParameterizedConstructor) {
    Trapeze trap(5.0, 3.0, 2.0);
    EXPECT_EQ(trap.operator double(), 8.0);
}

// Тест конструктора копирования
TEST(TrapezeTest, CopyConstructor) {
    Trapeze trap1(5.0, 3.0, 2.0);
    Trapeze trap2(trap1);
    EXPECT_EQ(trap2.operator double(), 8.0);
}

// Тест оператора копирования
TEST(TrapezeTest, CopyAssignmentOperator) {
    Trapeze trap1(5.0, 3.0, 2.0);
    Trapeze trap2;
    trap2 = trap1;
    EXPECT_EQ(trap2.operator double(), 8.0);
}

 TEST(TrapezeTest, EqualityOperator) {
    Trapeze trap1(5.0, 3.0, 2.0);
    Trapeze trap2(5.0, 3.0, 2.0);
    EXPECT_TRUE(trap1 == static_cast<const Figure&>(trap2));
}
