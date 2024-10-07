#include <stdio.h>

int main(void) {
    int n = 0, res_iterations = 0; 

    do {
        printf("Enter a number: ");
        scanf("%d", &n);
    } while (n <= 0);

    printf("(n^2*(n+1)^2)/4 = %d\n", ((n*n)*(n+1)*(n+1))/4);

    for(int i=1; i<=n; i++) {
        res_iterations += i*i*i;
    }

    printf("Sum: %d\n", res_iterations);
    return 0;
}