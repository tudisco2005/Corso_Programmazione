#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int val = INT_MAX;
    printf("Overflow:\n");
    printf("Val = %d\n", val);
    printf("Val + 1 = %d\n", val + 1);
    
    float val_f = FLT_MIN;
    printf("\nUnderflow:\n");
    printf("Val: %g\n", val_f);
    printf("Val / Flt_max: %g\n", val_f / FLT_MAX);

    return 0;
}