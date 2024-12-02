/*
Ordinamento BubbleSort con allocazione dinamica.
Tempo: 25 min.
Si scriva un programma che legga dalla console una successione di valori double,
e li memorizzi in una zona della memoria di dimensione appropriata. Chiedete
all’utente per prima cosa quanti valori double intenda inserire. Usate poi questa
informazione per eseguire un’appropriata chiamata alla funzione malloc. Dopo
aver letto e memorizzato i valori, il programma li ordina applicando l’algoritmo
BubbleSort — si veda l’Esercizio 11 della Lezione 4 — visualizza l’elenco ordinato,
libera la memoria allocata dinamicamente e termina
*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(double *arr, int len) {
    int sorted = 1;
    double tmp = 0;
    
    while(sorted) {
        sorted = 0;
        for(int i=0; i<len-1; i++) {
            if(arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sorted = 1;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    double *arr = (double *)malloc(n * sizeof(double));
    for(int i=0; i<n; i++){
        printf("Enter the %d elment: ", i);
        scanf("%lf", &arr[i]);
    }

    printf("\nBefore:\n");
    for(int i=0; i<n; i++){
        printf("%lf, ", arr[i]);
       
    }

    bubbleSort(arr, n);

    printf("\nAfter:\n");
    for(int i=0; i<n; i++){
        printf("%lf, ", arr[i]);
       
    }

    free(arr);

    return 0;
}