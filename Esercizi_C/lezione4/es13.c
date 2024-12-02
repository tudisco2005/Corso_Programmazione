/*
Mediana.
Tempo: 25 min.
Modificate la soluzione dell’Esercizio 10 di modo che il programma calcoli e vi-
sualizzi la mediana dei valori inseriti, oltre alla loro media, varianza e scarto qua-
dratico medio. Per ordinare i valori usate l’algoritmo BubbleSort implementato
nell’Esercizio 11
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

    int sorted = 1;
    double tmp = 0;

    //bubble sort
    while(sorted && N >= 2) {
        for(int i=0; i<N-1; i++) {
            if(values[i] > values[i+1]) { // swap
                tmp = values[i+1];
                values[i+1] = values[i];
                values[i] = tmp;
            }
        }

        for(int i=0; i<N-1; i++) {
            if (values[i] > values[i+1]) {
                sorted = 1;
                break;
            } else sorted = 0;
        }
    }

    printf("\nSorted:\n");
    for(int i=0; i<N; i++) printf("%lf, ", values[i]);

    if(N % 2 == 0)  printf("\n\nMediana: %lf\n", (values[N/2]+values[N/2-1])/2);
    else printf("\n\nMediana: %lf\n", values[N/2]);
    printf("Media: %lf\n", sum/N);
    printf("Varianza: %lf\n", varianza);
    printf("Errore quadratico medio: %lf\n", sqrt(varianza));

    return 0;
}