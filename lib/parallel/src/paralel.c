#include "paralel.h"
#include <pthread.h>
#include <unistd.h>

long sysconf(int name);
void *parallel (Parallel_num *parallel_num) {
    for (int i = 0; i < parallel_num->kol_works_elements; ++i) {
        int sum = 0;
        for (int j = 0; j < parallel_num->films_ptr[i].users_count; ++j) {
            sum += parallel_num->films_ptr[i].scores[j];
        }
        parallel_num->films_ptr[i].avg_score = (float) sum / (float) parallel_num->films_ptr[i].users_count;
        printf("%.2f",parallel_num->films_ptr[i].avg_score);
    }
    return(0);
}
int paral(Film *films, size_t films_count) {
    Parallel_num parallel_num;
    parallel_num.start_ptr = 0;
    parallel_num.films_ptr = films;
    parallel_num.kol_works_elements = (int) films_count / (int) sysconf(_SC_NPROCESSORS_ONLN);
    pthread_t threads[sysconf(_SC_NPROCESSORS_ONLN)];
    int status;
    for (int i = 0; i < sysconf(_SC_NPROCESSORS_ONLN); i++) {
        if ((i + 1) < sysconf(_SC_NPROCESSORS_ONLN)) {
            status = pthread_create(&threads[i], NULL, parallel, &parallel_num);
            parallel_num.start_ptr += parallel_num.kol_works_elements;
            if (status != 0) {
                return (1);
            }
        } else {
            parallel_num.kol_works_elements = (int) films_count - parallel_num.start_ptr;
            status = pthread_create(&threads[i], NULL, parallel, &parallel_num);
            if (status != 0) {
                return (1);
            }
        }
    }
   
    return 0;
}
