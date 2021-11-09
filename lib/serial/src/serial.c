#include "parser.h"

#include <string.h>

int parser(FILE* file, Film **films,size_t* films_count_max ,size_t* films_count ) {
    const size_t buffer_size = 300;
    char buffer[buffer_size];
    while (fgets(buffer, buffer_size, file)) {
        switch (buffer[0]) {
            case '#': {
                if ((*films_count) == (*films_count_max)) {
                    Film *films_ext = (Film *) malloc(sizeof(Film) * ((*films_count_max) *= 2));
                    for (size_t i = 0; i < (*films_count); ++i) {
                        films_ext[i] = (*films)[i];
                    }
                    free(*films);
                    *films = films_ext;
                }
                size_t new_film_name_len = strlen(buffer + 1);
                char *new_film_name = (char *) malloc(sizeof(char) * new_film_name_len);
                buffer[new_film_name_len] = '\0';
                strcpy(new_film_name, buffer + 1);
                (*films)[(*films_count)].film_name = new_film_name;
                (*films)[(*films_count)].users_count = 0;
                (*films)[(*films_count)].users_count_max = 2;
                (*films)[(*films_count)].scores = NULL;
                (*films)[(*films_count)].users = NULL;
                (*films)[(*films_count)].avg_score = -1;
                *films_count+=1;
                break;
            }
            case '@': {
                if (!films) {
                    return (1);
                }
                if (!(*films) [(*films_count) - 1].users) {
                    (*films)[(*films_count) - 1].users = (char **) malloc(
                            sizeof(char *) * (*films)[(*films_count) - 1].users_count_max);


                }
                if ((*films)[(*films_count) - 1].users_count == (*films)[(*films_count) - 1].users_count_max) {
                    char **new_user = (char **) malloc(sizeof(char *) * (((*films)[(*films_count) - 1].users_count_max) * 2));
                    for (size_t i = 0; i < (*films)[(*films_count) - 1].users_count; ++i) {
                        new_user[i] = (*films)[(*films_count) - 1].users[i];
                    }
                    free((*films)[(*films_count) - 1].users);
                    (*films)[(*films_count) - 1].users = new_user;
                }
                size_t new_user_name_len = strlen(buffer + 1);
                char *new_user_name = (char *) malloc(sizeof(char) * new_user_name_len);
                buffer[new_user_name_len] = '\0';
                strcpy(new_user_name, buffer + 1);
                (*films)[(*films_count) - 1].users[(*films)[(*films_count) - 1].users_count] = new_user_name;
                break;
            }
            case '%': {
                if (!films) {
                    return (1);
                }
                if (!(*films)[(*films_count) - 1].scores) {
                    (*films)[(*films_count) - 1].scores = (int *) malloc(
                            sizeof(int) * (*films)[(*films_count) - 1].users_count_max);


                }
                if ((*films)[(*films_count) - 1].users_count == (*films)[(*films_count) - 1].users_count_max) {
                    int *new_scores = (int *) malloc(
                            sizeof(int) * (((*films)[(*films_count) - 1].users_count_max) *= 2));
                    for (size_t i = 0; i < (*films)[(*films_count) - 1].users_count; ++i) {
                        new_scores[i] = (*films)[(*films_count) - 1].scores[i];
                    }
                    free((*films)[(*films_count) - 1].scores);
                    (*films)[(*films_count) - 1].scores = new_scores;
                }
                (*films)[(*films_count) - 1].scores[(*films)[(*films_count) - 1].users_count] = atoi(buffer + 1);
                (*films)[(*films_count) - 1].users_count++;
                break;
            }
            default: {
                printf("Unexpected symbol in %s\n", buffer);
                break;
            }
        }
    }
    return(0);
}