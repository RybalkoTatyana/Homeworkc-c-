add_library(paralel src/paralel.c)

target_include_directories(paralel PUBLIC include)
target_link_libraries(paralel parser)