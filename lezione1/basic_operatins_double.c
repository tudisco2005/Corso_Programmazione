#include <stdio.h>

int main() {
    double a=0.0,b=0.0;

    printf("Enter a number: ");
    scanf("%g", &a);

    printf("Enter a number: ");
    scanf("%g", &b);

    printf("\nOperations:\n");
    printf("Sum %g + %g = %ld\n", a,b,a+b);
    printf("Diff %g - %g = %ld\n",a,b,a-b);
    printf("Mult %g * %g = %ld\n",a,b,a*b);
    printf("Div %g / %g = %g\n",a,b,a/b);
    printf("Rest %g %% %g = %g\n",a,b,a % b); // % is only for integer

    return 0;
}