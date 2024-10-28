/*
Tempo: 25 min.
Scrivete un programma che implementi l’algoritmo di ordinamento BubbleSort se-
condo lo pseudocodice riportato in Figura 1. Per testare il programma dichiarate
e inizializzate nel vostro codice un array v di int o double di lunghezza modesta,
per esempio 5 elementi. Visualizzate il contenuto di v prima e dopo l’esecuzione
dell’algoritmo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main() {
    srand(time(NULL));
    double tmp;
    double nums[N];
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
    printf("\n");

    return 0;
}