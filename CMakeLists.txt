cmake_minimum_required(VERSION 3.20)
project(Homework2)

set(CMAKE_C_STANDARD 99)
find_package(Threads REQUIRED)
SET(CMAKE_CXX_FLAGS -pthread)
add_subdirectory(lib/reader)
add_subdirectory(lib/serial)
add_subdirectory(lib/parallel)
add_executable(Homework2 src/main.c)
target_link_libraries(Homework2 parser paralel serial Threads::Threads)