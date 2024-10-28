/*
Media aritmetica.
Tempo: 10 min.
Scrivete un programma che chieda all’utente di inserire 5 valori double, li memorizzi La chiamata
scanf("%lf",&x);
memorizza il numero
inserito dall’utente
nella variabile x di
tipo double.
in un array di double della dimensione corrispondente, calcoli la media aritmetica
dei valori inseriti, la visualizzi e termini.
*/

#include <stdio.h>
#include <string.h>

#define N 5

int main() {
    double values[N];
    double sum = 0L;

    for(int i=0; i<N; i++) {
        printf("Enter a number: ");
        scanf("%lf", &values[i]);
        sum += values[i];
    } 


    printf("\nMedia: %lf\n", sum/N);

    return 0;
}