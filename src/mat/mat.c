#include "mat.h"
#include <stdio.h>
#include <stddef.h>

void mat_print(Mat m) {
   for (size_t i = 0 ; i < m.rows ; i++) {
       for (size_t j = 0 ; j < m.cols ; j++) {
            printf(" %f", m.data[i * m.cols + j]);
       }
       printf("\n");
   }
}

void mat_mul(Mat c, Mat a, Mat b) {
    for (size_t i = 0 ; i < a.rows ; i++) {
        for (size_t j = 0 ; j < b.cols ; j++) {
            for (size_t k = 0 ; k < a.cols ; k++) {
                c.data[i * c.cols + j] += a.data[i * a.cols + k] * b.data[k * b.rows + j];
            }
        }
    }
}
