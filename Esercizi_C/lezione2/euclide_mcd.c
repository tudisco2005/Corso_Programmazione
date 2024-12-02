#include <stdio.h>

int main(void) {
    int a = 0, b = 0, iterations = 0;

    printf("Enter a number: ");
    scanf("%d", &a);

    if(a <= 0) {
        printf("Value not acceped only positive integer\n");
        return -1;
    }

    printf("Enter a number: ");
    scanf("%d", &b);

    if(b <= 0) {
        printf("\nValue not acceped only positive integer\n");
        return -1;
    }

    while (a != b) {
        if (a<b) b -= a;
        if (a>b) a -= b;
        iterations += 1;
    }
    
    printf("\nM.C.D = %d\n",a);
    printf("Iterations: %d\n", iterations);

    return 0;
}