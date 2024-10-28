/*
Modificate la soluzione dell’Esercizio 11 di modo che il programma calcoli e vi-
sualizzi il numero di scambi eseguiti. A tal fine utilizzate una variabile contatore
di tipo int, inizializzata a zero, che incrementerete ogni volta che il programma
esegue uno scambio. Visualizzate il numero di scambi prima di terminare l’esecu-
zione. Calcolate poi il valore N2/2, dove N è la lunghezza dell’array da ordinare, e
visualizzate anche questo valore..
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

int main() {
    srand(time(NULL));
    double tmp;
    double nums[N];
    int swapCounter = 0;
    for(int i=0; i<N; i++) nums[i] = (double)rand()/RAND_MAX*2.0-1.0;//float in range -1 to 1


    printf("Original:\n");
    for(int i=0; i<N; i++) printf("%lf, ", nums[i]);

    int sorted = 1;

    //bubble sort
    while(sorted) {
        for(int i=0; i<N-1; i++) {
            if(nums[i] > nums[i+1]) { // swap
                tmp = nums[i+1];
                nums[i+1] = nums[i];
                nums[i] = tmp;
                swapCounter++;
            }
        }

        for(int i=0; i<N-1; i++) {
            if (nums[i] > nums[i+1]) {
                sorted = 1;
                break;
            } else sorted = 0;
        }
    }
    
    

    printf("\n\nSorted:\n");
    for(int i=0; i<N; i++) printf("%lf, ", nums[i]);
    printf("\nSwaps: %d, N^2/2: %lf\n", swapCounter, (N*N)/2);

    return 0;
}