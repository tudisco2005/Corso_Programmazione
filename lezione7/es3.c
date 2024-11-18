/*
Tempo: 30 min.
Si modifichi il programma scritto per risolvere l’Esercizio 2 di modo che il menu
diventi:
1. Inserisci elenco di double.
2. Ordina elenco.
3. Visualizza elenco.
4. Aggiungi elementi.
5. Termina.
L’opzione 4 permette all’utente di aggiungere valori double in coda all’elenco di
valori corrente. Chiedete preliminarmente all’utente quanti valori intende aggiungere all’elenco corrente. Usate realloc per ridimensionare la memoria allocata
dinamicamente. Se l’utente sceglie 4 prima di aver inserito un elenco di double
tramite 1, il programma informa l’utente della necessità di inserire dei dati e torna
al menu. Per il resto il funzionamento del programma è come nell’Esercizio 2.
*/
#include <stdio.h>
#include <stdlib.h>

enum {INSERT = 1, SORT, PRINT, ADD_ELM, EXIT};

void bubbleSort(double *arr, int len) {
    int swapped = 1;
    double tmp = 0;
    
    while(swapped) {
        swapped = 0;
        for(int i = 0; i < len-1; i++) {
            if(arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                swapped = 1;
            }
        }
    }
    printf("\nList sorted\n");
}

int menu() {
    int choice;
    do {
        printf("\nOptions:\n");
        printf("1. Inserisci elenco di double.\n");
        printf("2. Ordina elenco.\n");
        printf("3. Visualizza elenco.\n");
        printf("4. Aggiungi elementi.\n");
        printf("5. Termina.\n");
        printf("-> ");
        scanf("%d", &choice);
        if(choice < INSERT || choice > EXIT) printf("Invalid choice, retry\n");
    } while(choice < INSERT || choice > EXIT);
    return choice;
}

void printList(double *arr, int n) {
    printf("\nCurrent list:\n");
    for(int i = 0; i < n; i++) {
        printf("%lf", arr[i]);
        if (i < n-1) printf(", ");
    }
    printf("\n");
}

int isInitialized(double *arr, int n) {
    if(arr == NULL || n <= 0) {
        printf("You must insert a list of double first.\n");
        return 0;
    }
    return 1;
}

double* enterList(double *arr, int *n) {
    if(arr != NULL) {
        free(arr);
        arr = NULL;
    }
    
    printf("Enter the number of elements: ");
    scanf("%d", n);
    if(*n <= 0) {
        printf("You must insert at least one element.\n");
        return NULL;
    }
    
    arr = (double *)malloc(*n * sizeof(double));
    if(arr == NULL) {
        printf("Memory allocation failed.\n");
        *n = 0;
        return NULL;
    }
    
    for(int i = 0; i < *n; i++) {
        printf("Enter the %d element: ", i);
        scanf("%lf", &arr[i]);
    }
    return arr;
}

int addElement(double **arr, int *n) {
    int newElm;
    printf("Enter the number of elements to add: ");
    scanf("%d", &newElm);
    if(newElm <= 0) {
        printf("You must insert at least one element.\n");
        return 0;
    }

    double *temp = (double *)realloc(*arr, (*n + newElm) * sizeof(double));
    if(temp == NULL) {
        printf("Memory reallocation failed.\n");
        return 0;
    }
    *arr = temp;

    for(int i = *n; i < (*n + newElm); i++) {
        printf("Enter the %d element: ", i);
        scanf("%lf", &(*arr)[i]);
    }
    *n += newElm;
    return 1;
}

int main() {
    int n = 0;
    double *arr = NULL;

    while(1) {
        switch (menu()) {
            case INSERT:
                arr = enterList(arr, &n);
                break;
            case SORT:
                if(isInitialized(arr, n)) bubbleSort(arr, n);
                break;
            case PRINT:
                if(isInitialized(arr, n)) printList(arr, n);
                break;
            case ADD_ELM:
                if(isInitialized(arr, n)) addElement(&arr, &n);
                break;
            case EXIT:
                free(arr);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}