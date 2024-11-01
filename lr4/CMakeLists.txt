cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

# Добавление исполняемого файла для основного приложения
add_executable(main main.cpp)

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
target_link_libraries(tests gtest_main)
add_test(NAME MyProjectTests COMMAND tests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-psabi")