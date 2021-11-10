#include "serial.h"
int serial(size_t films_count, Film *films) {
    for (int i = 0; i < films_count; ++i) {
        int sum = 0;
        for (int j = 0; j < films[i].users_count; ++j) {
            sum += films[i].scores[j];
        }
        films[i].avg_score = (float) sum / (float) films[i].users_count;
    }
return(0);
}