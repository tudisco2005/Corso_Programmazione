#include <stdio.h>

int main() {
    int input_i = 0;
    float input_f = 0.0;

    printf("\nEnter a int input: ");
    scanf("%d", &input_i);
    printf("You entered: %d\n", input_i);

    printf("\nEnter a float input: ");
    scanf("%g", &input_f);
    printf("\nYou entered: %g\n", input_f);

    return 0;
}