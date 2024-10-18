cmake_minimum_required(VERSION 3.10)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${INCLUDE_DIR})
# Автоматический поиск всех .cpp файлов в папке src
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES false ${SOURCE_DIR}/*.cpp)
# Создание библиотеки из исходников
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${CMAKE_PROJECT_NAME}_lib)
 
# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(tests tests/test.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)
add_test(NAME MyProjectTests COMMAND tests)