/*
L’algoritmo euclideo: input dell’utente.
Tempo: 10 min.
Modificate la vostra soluzione all’Esercizio 6 in modo che sia l’utente a inserire da
terminale i valori delle variabili a e b, all’inizio dell’esecuzione
*/

#include <stdio.h>

int main() {
    int a, b, aux;
    
    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter a number: ");
    scanf("%d", &b);

    while(b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }

    printf("M.C.D = %d\n", a);

    return 0;
}