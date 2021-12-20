cmake_minimum_required(VERSION 3.6)

project(HW-1)

# Flags to generate test coverage
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Wno-unused -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Wall -Wno-unused -Werror -Wpedantic -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

# Make task library
add_library(task STATIC project/task/src/task.c)
target_include_directories(task PUBLIC project/task/include)

# Make menu library
add_library(menu STATIC project/menu/src/menu.c)
target_include_directories(menu PUBLIC project/menu/include)
target_link_libraries(menu task)

# Make executable program
add_executable(main.out project/cmd/src/main.c)
target_include_directories(main.out PUBLIC project/menu/include)
target_link_libraries(main.out menu)

# Find libraries for test
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Make executable test program
add_executable(test.out test/main.cpp)
target_link_libraries(test.out task ${GTEST_LIBRARIES} Threads::Threads)
