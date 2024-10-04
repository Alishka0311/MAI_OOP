#include <gtest/gtest.h>
#include "../include/Twelve.h"

// Тесты для конструктора по умолчанию
TEST(TwelveTest, DefaultConstructor) {
    Twelve num;
    EXPECT_EQ(num.getSize(), 1); // Проверка, что размер объекта равен 1
    EXPECT_EQ(num.getData()[0], '0'); // Проверка, что первый элемент данных равен '0'
}

// Тесты для конструктора с размером и символом
TEST(TwelveTest, ConstructorWithSizeAndChar) {
    Twelve num(4, '1');
    EXPECT_EQ(num.getSize(), 4); // Проверка, что размер объекта равен 4
    EXPECT_EQ(num.getData()[0], '1'); // Проверка, что первый элемент данных равен '1'
    EXPECT_EQ(num.getData()[1], '1');  
    EXPECT_EQ(num.getData()[2], '1');  
    EXPECT_EQ(num.getData()[3], '1');  
}

// Тесты для конструктора с initializer_list
TEST(TwelveTest, ConstructorWithInitializerList) {
    Twelve num({ '1', '2', '3' });
    EXPECT_EQ(num.getSize(), 3); // Проверка, что размер объекта равен 3
    EXPECT_EQ(num.getData()[2], '1');  
    EXPECT_EQ(num.getData()[1], '2');  
    EXPECT_EQ(num.getData()[0], '3');  
}

// Тесты для конструктора копирования
TEST(TwelveTest, CopyConstructor) {
    Twelve num1("123");
    Twelve num2(num1);
    EXPECT_EQ(num2.getSize(), 3); // Проверка, что размер объекта равен 3
    EXPECT_EQ(num2.getData()[2], '1');  
    EXPECT_EQ(num2.getData()[1], '2');  
    EXPECT_EQ(num2.getData()[0], '3'); 
}

// Тесты для конструктора перемещения
TEST(TwelveTest, MoveConstructor) {
    Twelve num1("123");
    Twelve num2(std::move(num1));
    EXPECT_EQ(num2.getSize(), 3); // Проверка, что размер объекта равен 3
    EXPECT_EQ(num2.getData()[2], '1'); 
    EXPECT_EQ(num2.getData()[1], '2');  
    EXPECT_EQ(num2.getData()[0], '3'); 
}

// Тесты для конструктора со строкой
TEST(TwelveTest, ConstructorWithString) {
    Twelve num("123");
    EXPECT_EQ(num.getSize(), 3); // Проверка, что размер объекта равен 3
    EXPECT_EQ(num.getData()[2], '1');  
    EXPECT_EQ(num.getData()[1], '2');  
    EXPECT_EQ(num.getData()[0], '3'); 
}

// Тесты для оператора копирующего присваивания
TEST(TwelveTest, CopyAssignmentOperator) {
    Twelve num1("123");
    Twelve num2 = num1;
    EXPECT_EQ(num2.getSize(), 3); // Проверка, что размер объекта равен 3
    EXPECT_EQ(num2.getData()[2], '1');  
    EXPECT_EQ(num2.getData()[1], '2');  
    EXPECT_EQ(num2.getData()[0], '3');  
}

// Тесты для оператора перемещающего присваивания
TEST(TwelveTest, MoveAssignmentOperator) {
    Twelve num1("123");
    Twelve num2 = std::move(num1);
    EXPECT_EQ(num2.getSize(), 3); // Проверка, что размер объекта равен 3
    EXPECT_EQ(num2.getData()[2], '1');  
    EXPECT_EQ(num2.getData()[1], '2');  
    EXPECT_EQ(num2.getData()[0], '3');  
}

// Тесты для граничных значений
TEST(TwelveTest, BoundaryValues) {
    Twelve num1("B");
    Twelve num2("1");
    Twelve num3 = num1 + num2;

    EXPECT_EQ(num3.getSize(), 2); // Проверка, что размер объекта равен 2
    EXPECT_EQ(num3.getData()[1], '1'); 
    EXPECT_EQ(num3.getData()[0], '0'); 
}

// Тесты для больших чисел
TEST(TwelveTest, LargeNumbers) {
    Twelve num1("AAAA");
    Twelve num2("BBBB");
    Twelve num3 = num1 + num2;

    EXPECT_EQ(num3.getSize(), 5); // Проверка, что размер объекта равен 5
    EXPECT_EQ(num3.getData()[4], '1');  
    EXPECT_EQ(num3.getData()[3], 'A');  
    EXPECT_EQ(num3.getData()[2], 'A');  
    EXPECT_EQ(num3.getData()[1], 'A');  
    EXPECT_EQ(num3.getData()[0], '9');  
}

// Тесты для сложения
TEST(TwelveTest, Addition) {
    Twelve num1("1111");
    Twelve num2("111");
    num1 += num2;
    EXPECT_EQ(num1.getSize(), 4); // Проверка, что размер объекта равен 4
    EXPECT_EQ(num1.getData()[3], '1');  
    EXPECT_EQ(num1.getData()[2], '2');  
    EXPECT_EQ(num1.getData()[1], '2');  
    EXPECT_EQ(num1.getData()[0], '2');  
}

// Тесты для вычитания
TEST(TwelveTest, Subtraction) {
    Twelve num1("2222");
    Twelve num2("111");
    num1 -= num2;

    EXPECT_EQ(num1.getSize(), 4); // Проверка, что размер объекта равен 4
    EXPECT_EQ(num1.getData()[3], '2');  
    EXPECT_EQ(num1.getData()[2], '1');  
    EXPECT_EQ(num1.getData()[1], '1'); 
    EXPECT_EQ(num1.getData()[0], '1');  
}

// Тесты для равенства
TEST(TwelveTest, Equality) {
    Twelve num1("1111");
    Twelve num2("1111");
    Twelve num3("2222");

    EXPECT_TRUE(num1 == num2);
    EXPECT_FALSE(num1 == num3);
}

// Тесты для сравнения больше/меньше
TEST(TwelveTest, Comparison) {
    Twelve num1("1111");
    Twelve num2("2222");

    EXPECT_TRUE(num1 < num2);
    EXPECT_FALSE(num1 > num2);
    EXPECT_TRUE(num1 != num2);
}

// Тест на исключение при вычитании
TEST(TwelveTest, SubtractionException) {
    Twelve num1("111");
    Twelve num2("2222");

    EXPECT_THROW(num1 -= num2, std::runtime_error);
}

// Тест на исключение при недопустимых символах
TEST(TwelveTest, InvalidCharacter) {
    EXPECT_THROW(Twelve num("1C2"), std::logic_error);
}

// Тест на самоприсваивание
TEST(TwelveTest, SelfAssignment) {
    Twelve num("1111");
    EXPECT_THROW(num = num, std::runtime_error);
}


// Тесты для вычитания с заимствованием
TEST(TwelveTest, SubtractionBorrow) {
    Twelve num1("1000"); 
    Twelve num2("1");    
    Twelve num3 = num1 - num2;
    EXPECT_EQ(num3.getSize(), 3);          
    EXPECT_EQ(num3.getData()[2], 'B');     
    EXPECT_EQ(num3.getData()[1], 'B');    
    EXPECT_EQ(num3.getData()[0], 'B');    
 
}


// Тесты для сложения с нулем
TEST(TwelveTest, AdditionWithZero) {
    Twelve num1("123");
    Twelve num2("0");
    Twelve num3 = num1 + num2;
    EXPECT_EQ(num3.getSize(), 3); 
    EXPECT_EQ(num3.getData()[2], '1'); 
    EXPECT_EQ(num3.getData()[1], '2'); 
    EXPECT_EQ(num3.getData()[0], '3'); 
}

// Тесты для вычитания с нулем
TEST(TwelveTest, SubtractionWithZero) {
    Twelve num1("123");
    Twelve num2("0");
    Twelve num3 = num1 - num2;
    EXPECT_EQ(num3.getSize(), 3); 
    EXPECT_EQ(num3.getData()[2], '1'); 
    EXPECT_EQ(num3.getData()[1], '2'); 
    EXPECT_EQ(num3.getData()[0], '3');
}

// Тесты для сравнения с нулем
TEST(TwelveTest, ComparisonWithZero) {
    Twelve num1("0");
    Twelve num2("1");
    EXPECT_TRUE(num1 < num2); // Проверка, что num1 меньше num2
    EXPECT_FALSE(num1 > num2); // Проверка, что num1 не больше num2
    EXPECT_TRUE(num1 != num2); // Проверка, что num1 не равен num2
}

// Тесты для сравнения с самим собой
TEST(TwelveTest, ComparisonWithSelf) {
    Twelve num("123");
    EXPECT_TRUE(num == num); // Проверка, что num равен самому себе
    EXPECT_FALSE(num != num); // Проверка, что num не не равен самому себе
}

// Главная функция тестов
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}