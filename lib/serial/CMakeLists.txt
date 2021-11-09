add_library(serial src/serial.c)

target_include_directories(serial PUBLIC include)
target_link_libraries(serial parser)