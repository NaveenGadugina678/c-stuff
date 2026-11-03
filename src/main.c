#include <stdlib.h>
#include <stdio.h>
#include "mat/mat.h"
#include <time.h>

#define MAT_SIZE 512

float randf(void) {
    return (float)rand() / (float)RAND_MAX;
}

int main() {
    float *mat_data = malloc(MAT_SIZE * MAT_SIZE * 3 * sizeof(*mat_data));

    Mat a = {
        .rows = MAT_SIZE,
        .cols = MAT_SIZE,
        .data = mat_data + 0 * MAT_SIZE * MAT_SIZE
    };

    Mat b = {
        .rows = MAT_SIZE,
        .cols = MAT_SIZE,
        .data = mat_data + 1 * MAT_SIZE * MAT_SIZE
    };

    Mat c = {
        .rows = MAT_SIZE,
        .cols = MAT_SIZE,
        .data = mat_data + 2 * MAT_SIZE * MAT_SIZE
    };
    
    mat_func(a, randf);
    mat_func(b, randf);

    uint64_t start = clock_gettime_nsec_np(CLOCK_MONOTONIC);
    mat_mul(c, a, b);
    uint64_t dur_ns = clock_gettime_nsec_np(CLOCK_MONOTONIC) - start;
    float dur_s = dur_ns / 1e9;
    
    printf("mat mul time : %.5f s\n", dur_s);

    free(mat_data); // freeing at the actually doesn't make any sense since we are closing the program.

    return 0;
}
