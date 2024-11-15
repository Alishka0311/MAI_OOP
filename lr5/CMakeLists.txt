cmake_minimum_required(VERSION 3.10)
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавление опций компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

# Установка директории для заголовочных файлов
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

# Добавление исходных файлов для основного приложения
set(SOURCE_FILES
    main.cpp              # Главный исходный файл
    src/MemoryPool.cpp    # Реализация MemoryPool
    src/CustomQueue.cpp   # Реализация CustomQueue
)

# Добавление исполняемого файла для основного приложения
add_executable(main ${SOURCE_FILES})

# Установка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Исходные файлы для тестов
set(TEST_FILES
    tests/test.cpp
)

# Добавление исполняемого файла для тестов
add_executable(tests ${TEST_FILES} src/MemoryPool.cpp src/CustomQueue.cpp)

# Линковка тестов с GoogleTest
target_link_libraries(tests gtest_main)

# Регистрируем тесты в CMake
add_test(NAME MyProjectTests COMMAND tests)

# Отключаем предупреждения при линковке
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-psabi")