#include <limits.h>
#include <float.h>
#include <stdio.h>

int main() {
    printf("Int -> %d byte(%d bits)\n Min: %d - Max: %d\n", sizeof(int), sizeof(int)*8, INT_MIN, INT_MAX);
    printf("Char -> %d byte(%d bits)\n Min: %d - Max: %d\n", sizeof(char), sizeof(char)*8,CHAR_MIN, CHAR_MAX);
    printf("Float -> %d byte(%d bits)\n Min: %g - Max: %g\n", sizeof(float), sizeof(float)*8,FLT_MIN, FLT_MAX);
    printf("Double -> %d byte(%d bits)\n Min: %g - Max: %g\n", sizeof(double), sizeof(double)*8,DBL_MIN, DBL_MAX);
    return 0;
}