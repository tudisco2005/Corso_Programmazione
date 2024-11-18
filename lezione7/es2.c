/*
Esercizio 2
Ordinamento BubbleSort con allocazione dinamica, menu, e funzioni.
Tempo: 35 min.
Si scriva un programma che visualizzi un menu come segue:
1. Inserisci elenco di double.
2. Ordina elenco.
3. Visualizza elenco.
4. Termina.
Se l’utente sceglie 4 il programma termina. Se l’utente sceglie 2 o 3 prima di aver
inserito un elenco di double, il programma informa l’utente della necessità di inse-
rire dei dati e torna al menu. Se l’utente sceglie 1 il programma permette all’utente
di inserire un elenco di valori di tipo double, e li memorizza usando le funzioni
di stdlib.h per l’allocazione dinamica della memoria. Chiedete preliminarmente
all’utente quanti valori intende inserire, come nell’Esercizio 1. Stabilite un com-
portamento sensato del programma nel caso in cui l’utente scelga 1 e inserisca,
o tenti di inserire, zero valori. L’opzione 3 permette di visualizzare l’elenco cor-
rente. L’opzione 2 ordina l’elenco corrente applicando l’algoritmo BubbleSort. Se
l’utente sceglie 1 dopo aver già inserito un elenco, il programma scarta il vecchio
elenco (deallocando la memoria con free) e permette all’utente di inserirne uno
nuovo, allocando la memoria necessaria di conseguenza. Strutturate il programma
in funzioni appropriate
*/

#include <stdio.h>
#include <stdlib.h>

enum {INSERT = 1, SORT, PRINT, EXIT};

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
    printf("\nList sorted\n");
}

int menu(){
    int choice;
    do {
        printf("\nOptions:\n");
        printf("1. Inserisci elenco di double.\n");
        printf("2. Ordina elenco.\n");
        printf("3. Visualizza elenco.\n");
        printf("4. Termina.\n");
        printf("-> ");
        scanf("%d", &choice);
        if(choice < INSERT || choice > EXIT) printf("Invalid choice.\n");
    } while(choice < INSERT || choice > EXIT);
    return choice;
}

void printList(double *arr, int n) {
    printf("\nCurrent list:\n");
    for(int i=0; i<n; i++){
        printf("%lf, ", arr[i]);
    }
}

int isInizialised(double *arr, int n) {
    if(arr == NULL || n <= 0 ) {
        printf("You must insert a list of double first.\n");
        return 0;
    }
    return 1;
}

double* enterList(double *arr, int *n) {
    if(arr != NULL) free(arr);
    
    printf("Enter the number of elements: ");
    scanf("%d", n);
    if(*n <= 0) {
        printf("You must insert at least one element.\n");
        return NULL;
    }
    
    arr = (double *)malloc(*n * sizeof(double));
    for(int i=0; i<*n; i++){
        printf("Enter the %d elment: ", i);
        scanf("%lf", &arr[i]);
    }
    return arr;
}

int main() {
    int n = -1;
    double *arr = NULL;

    while(1){
        switch (menu()){
            case INSERT: {
                arr = enterList(arr, &n);
                break;
            }        
            case SORT: {
                if(isInizialised(arr, n)) bubbleSort(arr, n);
                break;
            }
            case PRINT: {
                if(isInizialised(arr, n)) printList(arr, n);
                break;
            }
            case EXIT: {
                if (arr != NULL) free(arr);
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}