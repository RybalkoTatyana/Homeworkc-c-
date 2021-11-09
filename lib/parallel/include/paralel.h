#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

typedef struct Parallel_num {
    Film * films_ptr;
    int start_ptr;
    int kol_works_elements;
} Parallel_num ;


int paral(Film *films, size_t films_count) ;