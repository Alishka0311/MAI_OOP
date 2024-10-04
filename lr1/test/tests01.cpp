#include <gtest/gtest.h>
#include "../include/intToBinaryArray.h"

TEST(test_01, basic_test_set) {
    int arr[32] = {0}; 
    int ans[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    int value = 1;
    intToBinaryArray(value, arr);

    for (int i = 0; i < 32; i++) {
        ASSERT_TRUE(arr[i] == ans[i]);
    }
}

TEST(test_02, basic_test_set) {
    int arr[32] = {0}; 
    int ans[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0};
    int value = 10;
    intToBinaryArray(value, arr);

    for (int i = 0; i < 32; i++) {
        ASSERT_TRUE(arr[i] == ans[i]);
    }
}

TEST(test_03, basic_test_set) {
    int arr[32] = {0}; 
    int ans[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1};
    int value = 5;
    intToBinaryArray(value, arr);

    for (int i = 0; i < 32; i++) {
        ASSERT_TRUE(arr[i] == ans[i]);
    }
}

TEST(test_04, basic_test_set) {
    int arr[32] = {0}; 
    int ans[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int value = 0;
    intToBinaryArray(value, arr);

    for (int i = 0; i < 32; i++) {
        ASSERT_TRUE(arr[i] == ans[i]);
    }
}

TEST(test_05, basic_test_set) {
    int arr[32] = {0}; 
    int ans[32] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0};
    int value = 100;
    intToBinaryArray(value, arr); 

    for (int i = 0; i < 32; i++) {
        ASSERT_TRUE(arr[i] == ans[i]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}