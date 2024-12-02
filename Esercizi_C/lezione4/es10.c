/*
Varianza e scarto quadratico medio.
Tempo: 15 min.
Modificate la soluzione dell’Esercizio 9 di modo che il programma calcoli e visualizzi
la varianza e lo scarto quadratico medio dei valori inseriti, oltre alla loro media
aritmetica
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

// used a variabile lenght array

int main() {
    int N;
    double sum = 0L;

    do {    
        printf("How many numbers do you want to enter: ");
        scanf("%d", &N);
    } while(N <= 0);

    double values[N];

    for(int i=0; i<N; i++) {
        printf("Enter a number: ");
        scanf("%lf", &values[i]);
        sum += values[i];
    } 

    //varianza
    double varianza = 0L;
    for(int i=0; i<N; i++) {
        varianza += pow(values[i] - (sum/N),2);
    }
    varianza /= N;


    printf("\nMedia: %lf\n", sum/N);
    printf("Varianza: %lf\n", varianza);
    printf("Errore quadratico medio: %lf\n", sqrt(varianza));

    return 0;
}