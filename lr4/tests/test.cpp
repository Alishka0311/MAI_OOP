#include <gtest/gtest.h>
#include "point.h"
#include "rectangle.h"
#include "square.h"
#include "trap.h"
#include "array.h"

// Тест для класса Point
TEST(PointTest, Comparison) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(2.0, 3.0);

    EXPECT_EQ(p1, p2);
    EXPECT_NE(p1, p3);
}

// Тест для класса Rectangle
TEST(RectangleTest, AreaCalculation) {
    Rectangle<double> rect(Point<double>(0, 0), 5.0, 3.0);
    EXPECT_DOUBLE_EQ(rect.area(), 15.0);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle<double> rect(Point<double>(0, 0), 5.0, 3.0);
    Point<double> center = rect.center();
    EXPECT_DOUBLE_EQ(center.x, 2.5);
    EXPECT_DOUBLE_EQ(center.y, 1.5);
}

TEST(RectangleTest, VertexCoordinates) {
    Rectangle<double> rect(Point<double>(0, 0), 5.0, 3.0);

    // Проверяем координаты вершин прямоугольника
    std::vector<Point<double>> vertices = rect.vertices();
    EXPECT_EQ(vertices[0], Point<double>(0, 0));
    EXPECT_EQ(vertices[1], Point<double>(5, 0));
    EXPECT_EQ(vertices[2], Point<double>(5, 3));
    EXPECT_EQ(vertices[3], Point<double>(0, 3));
}

// Тест для класса Square
TEST(SquareTest, AreaCalculation) {
    Square<double> square(Point<double>(0, 0), 4.0);
    EXPECT_DOUBLE_EQ(square.area(), 16.0);
}

TEST(SquareTest, CenterCalculation) {
    Square<double> square(Point<double>(0, 0), 4.0);
    Point<double> center = square.center();
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 2.0);
}

TEST(SquareTest, VertexCoordinates) {
    Square<double> square(Point<double>(1, 0), 4.0);

    // Проверяем координаты вершин квадрата
    std::vector<Point<double>> vertices = square.vertices();
    EXPECT_EQ(vertices[0], Point<double>(1, 0));
    EXPECT_EQ(vertices[1], Point<double>(5, 0));
    EXPECT_EQ(vertices[2], Point<double>(5, 4));
    EXPECT_EQ(vertices[3], Point<double>(1, 4));
}

// Тест для класса Trapezoid
TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid<double> trap(Point<double>(0, 0), Point<double>(4, 0), Point<double>(3, 2), Point<double>(1, 2));
    EXPECT_DOUBLE_EQ(trap.area(), 6.0);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid<double> trap(Point<double>(0, 0), Point<double>(4, 0), Point<double>(3, 2), Point<double>(1, 2));
    Point<double> center = trap.center();
    EXPECT_DOUBLE_EQ(center.x, 2.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(TrapezoidTest, VertexCoordinates) {
    Trapezoid<double> trap(Point<double>(0, 0), Point<double>(4, 0), Point<double>(3, 2), Point<double>(1, 2));

    // Проверяем координаты вершин трапеции
    std::vector<Point<double>> vertices = trap.vertices();
    EXPECT_EQ(vertices[0], Point<double>(0, 0));
    EXPECT_EQ(vertices[1], Point<double>(4, 0));
    EXPECT_EQ(vertices[2], Point<double>(3, 2));
    EXPECT_EQ(vertices[3], Point<double>(1, 2));
}

// Тест для класса Array
TEST(ArrayTest, PushBackAndAccess) {
    Array<int> arr;
    arr.push_back(std::make_shared<int>(1));
    arr.push_back(std::make_shared<int>(2));
    arr.push_back(std::make_shared<int>(3));

    EXPECT_EQ(*arr[0], 1);
    EXPECT_EQ(*arr[1], 2);
    EXPECT_EQ(*arr[2], 3);
}

TEST(ArrayTest, RemoveElement) {
    Array<int> arr;
    arr.push_back(std::make_shared<int>(1));
    arr.push_back(std::make_shared<int>(2));
    arr.push_back(std::make_shared<int>(3));

    arr.remove(1);

    EXPECT_EQ(*arr[0], 1);
    EXPECT_EQ(*arr[1], 3);
    EXPECT_EQ(arr.size(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}