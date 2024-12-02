#include <stdio.h>

int main() {
    int a=0,b=0;

    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter a number: ");
    scanf("%d", &b);

    printf("\nOperations:\n");
    printf("Sum %d + %d = %ld\n", a,b,a+b);
    printf("Diff %d - %d = %ld\n",a,b,a-b);
    printf("Mult %d * %d = %ld\n",a,b,a*b);
    printf("Div %d / %d = %g\n",a,b,a/b);
    printf("Rest %d %% %d = %d\n",a,b,a%b);

    return 0;
}