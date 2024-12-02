#include <stdio.h>
#include <math.h>

int main(void) {
    double a = 0, b = 0, c = 0;

    do {
        printf("Enter a: ");
        scanf("%lf", &a);
    } while (a == 0);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    double delta = b*b-4*a*c;

    if (delta > 0) {
        printf("x1 = %lf\n", ((-b)+sqrt(delta))/(2*a));
        printf("x2 = %lf\n", ((-b)-sqrt(delta))/(2*a));
    } else if (delta < 0) {
        printf("No Solutions.\n");
    } else {
        printf("x = %lf\n", (-b)/(2*a));
    }
 
    return 0;
}