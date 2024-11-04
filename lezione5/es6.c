/*
Esercizio 6
Incrementi e decrementi.
Tempo: 15 min.
Scrivete un programma che dichiari un puntatore di tipo int e di nome pi, un
puntatore di tipo double e di nome pd e un puntatore di tipo char e di nome pc.
Definite poi degli array di int, double e char come segue:
int ai[]={0,1};
double ad[]={0.1,0.2};
char ac[]="pippo";
Fate puntare pi, pd e pc al primo elemento dell’array di tipo corrispondente, e
visualizzatelo tramite printf usando il puntatore. Incrementate ciascun puntatore
di uno e visualizzate il valore cui esso punta. Visualizzate anche i valori dei puntatori
— usate %p con printf — prima e dopo gli incrementi
*/

#include <stdio.h>

int main() {
    int *pi;
    double *pd;
    char *pc;

    int ai[]={0,1};
    double ad[]={0.1,0.2};
    char ac[]="pippo";

    pi = ai;
    pd = ad;
    pc = ac;

    printf("Elmento intero: %d\n", *pi);
    printf("Elmento double: %lf\n", *pd);
    printf("Elmento char: %c\n", *pc);

    printf("----Incremento----\n");

    pi++;
    pd++;
    pc++;
    printf("Elmento intero: %d\n", *pi);
    printf("Elmento double: %lf\n", *pd);
    printf("Elmento char: %c\n", *pc);

    return 0;
}