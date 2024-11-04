#include <stdio.h>
#include <math.h>

// ax^2 + bx + c = 0 con a, b e c presi come input, 

double delta(double a, double b, double c) {
    return pow(b,2) - (4*a*c);
}

int main(void) {
    double a,b,c;

    printf("ax^2 + bx + c = 0\n");
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    if (a == 0) {
        printf("a must not be zero for a quadratic equation\n");
        return 1;
    }

    printf("\nSolutions:\n");
    if (delta(a,b,c)>0) {
        printf("x1 = %lf\n", ((-b)+delta(a,b,c))/(2*a));
        printf("x2 = %lf\n", ((-b)-delta(a,b,c))/(2*a));
    } else if(delta(a,b,c)==0) {
        printf("x = %lf\n", ((-b)/(2*a)));
    } else {
        printf("No real solution\n");
    }

    return 0;
}