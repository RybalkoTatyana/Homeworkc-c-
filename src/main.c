#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int main() {

    FILE *file;
//    Film **film_arr = (Film **) malloc(buff_film_max_len);
    file = fopen("/home/tanya/Desktop/HomeworkC/data/films.txt", "r");

    const size_t buffer_size = 100;
    char buffer[buffer_size];
    size_t films_count_max = 2;
    size_t films_count = 0;
    Film *films = (Film *) malloc(sizeof (Film) * films_count_max);
    if(!films)
    {

    }
    scanf("%s", buffer);
    char * recommendation_for_name = (char*) malloc(strlen(buffer));
    strcpy(recommendation_for_name,buffer);


    parser(file, &films, &films_count_max, &films_count);



        for (int i = 0; i < films_count; ++i) {
            printf("Film: %s\n", films[i].film_name);
            for (int j = 0; j < films[i].users_count; ++j) {
                printf("\tUser %s scored this film in %i\n", films[i].users[j], films[i].scores[j]);

            }

        }
    for (int i = 0; i <films_count; ++i) {
        int sum=0;
        for (int j = 0; j <films[i].users_count; ++j)
        {
            sum+=films[i].scores[j];
        }
        films[i].avg_score=(float)sum/(float)films[i].users_count;
    }

    //сортировка
    int *index = (int*) malloc(sizeof (int) * films_count);
    for (int i=0; i<films_count; i++)
        index[i] = i;

    for (int i=0; i<films_count; i++)
        for (size_t j=films_count-1; j>i; j--)
            if (films[j].avg_score  > films[j-1].avg_score)
            {
                float temp=films[j].avg_score;
                films[j].avg_score= films[j-1].avg_score;
                films[j-1].avg_score= temp;
                int temp1 = index[j];
                index[j] = index[j-1];
                index[j-1] = temp1;
            }
    int kol_films = 0 ;
    int index_film = 0;
    while( (kol_films < 10)&(index_film<films_count)){
        int index_element=index[index_film];
        for (int i = 0; i < films[index_element].users_count; ++i)
            if (strcmp(recommendation_for_name, films[index_element].users[i])) {
                printf("%s\n", films[index_element].film_name);
                printf("%.2f\n", films[index_film].avg_score);
                kol_films++;
                break;
            }
        index_film++;

    }
    return(0);
}

////free mem
////    for (int i = 0; i <buff_film_real_len; ++i) {
////        for (int j = 0; j <film_arr[i]->len_mas; ++j)
////        {
////            free(film_arr[i]->name_arr[j]);
////        }
////        free(film_arr[i]->num_arr);
////        //film_arr[i]->num_arr = NULL;
////        free(film_arr[i]->name_arr);
////       // film_arr[i]->name_arr = NULL;
////        free(film_arr[i]);
////      //  film_arr[i] = NULL;
////    }
////    free(film_arr);
////    film_arr = NULL;
////   // free
