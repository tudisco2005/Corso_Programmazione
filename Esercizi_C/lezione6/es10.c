/*
Distanza euclidea nel piano.

Tempo: 15 min.

Si scriva un programma che definisca il tipo Vett come una struttura di due campi,
ciascuno di tipo double, che rappresentano le coordinate di un punto nel piano.
Chiamate i due campi x e y, rispettivamente.
Il programma chiede all’utente di inserire le coordinate di due punti del piano,
ne calcola la distanza invocando una funzione di prototipo double dist(Vett,
Vett), visualizza il risultato e termina.
*/

#include <stdio.h>
#include <math.h>

typedef struct Vett{
    double x;
    double y;
} Vett;

double pointDistance(Vett a, Vett b) {
    return (double) sqrt(pow((a.x - b.x),2) + pow(a.y - b.y,2));
}

int main() {
    Vett a, b;

    printf("Enter the Ax cordinate: ");
    scanf("%lf", &a.x);
    printf("Enter the Ay cordinate: ");
    scanf("%lf", &a.y);


    printf("Enter the Bx cordinate: ");
    scanf("%lf", &b.x);
    printf("Enter the By cordinate: ");
    scanf("%lf", &b.y);

    printf("Euclidian distance: %lf\n", pointDistance(a,b));

    return 0;
}