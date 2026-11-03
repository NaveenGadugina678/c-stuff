#include <stdlib.h>
#include <stdio.h>
#include "mat/mat.h"

int main() {
    Mat a = {.rows = 2, .cols = 2, .data = (float[]){3, 5, 5, 6}};
    Mat b = {.rows = 2, .cols = 2, .data = (float[4]){1, 7, -8, 3}};
    Mat c = {.rows = 2, .cols = 2, .data = (float[4]){0}};
    
    mat_mul(c, a, b);
    mat_print(c);
    return 0;
}
