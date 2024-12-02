/*
Unire e dividere due array con allocazione dinamica.
Tempo: 25 min.
Si scriva un programma che legga dalla console due successione di valori int, inseriti
dall’utente, che verranno memorizzati all’interno di due aree di memoria, allocate
staticamente, di dimensione N 100. Chiedete all’utente per prima cosa quanti valori
int intenda inserire per entrambi gli array. Implementate una funzione merge che,
ricevuti tali array e il numero di elementi contenuti in essi, allochi dinamicamente
un nuovo array che contenga esattamente tutti e soli i valori dei due array, e lo
restituisca. Se il primo array contiene 3 valori, e il secondo ne conviene 5, l’array
creato ne dovrà contenere esattamente 8.
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

int merge(int **dts, int arr1[], int n1, int arr2[], int n2) {
    int ndst = n1 + n2;
    *dts = (int *)malloc(ndst * sizeof(int));
    if (*dts == NULL) {
        printf("Error: memory allocation failed\n");
        exit(1);
    }

    int k = 0;
    for (int i = 0; i < n1; i++) {
        (*dts)[k] = arr1[i];
        k++;
    }
    for (int i = 0; i < n2; i++) {
        (*dts)[k] = arr2[i];
        k++;
    } 
    
    return ndst;
}

void enterArrayElm(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the %d value: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void enterArray(char *msg, int *arr, int *n) {
    printf("%s", msg);
    do{
        scanf("%d", n);
        if(*n < 0 || *n > N) printf("Error: the number must be between 0 and %d\n", N);
    }while (*n < 0 || *n > N);
    enterArrayElm(arr, *n);
}

int main() {
    int arr1[N], arr2[N], *dst;
    int n1, n2, ndst;

    enterArray("Enter the number of elements for the first array: ", arr1, &n1);
    enterArray("Enter the number of elements for the second array: ", arr2, &n2);

    printf("\nFirst array: ");
    printArray(arr1, n1);

    printf("\nSecond array: ");
    printArray(arr2, n2);

    ndst = merge(&dst, arr1, n1, arr2, n2);

    printf("\nMerged array: ");
    printArray(dst, ndst);

    return 0;
}