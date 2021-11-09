//#ifdef PARSER_H
#pragma once
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Film {
    char* film_name;
    char **users ;
    int *scores ;
    size_t users_count;
    size_t users_count_max;
    float avg_score;
} Film;

int parser(FILE* file, Film **films,size_t* films_count_max ,size_t* films_count );

//#endif