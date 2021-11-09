cmake_minimum_required(VERSION 3.20)
project(Homework2)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lib/serial)
add_executable(Homework2 src/main.c)
target_link_libraries(Homework2 parser)
