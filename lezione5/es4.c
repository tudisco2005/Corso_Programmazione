/*
LAB. PROG. — LEZIONE 5 5
Parte 2. Puntatori: primi esercizi, aritmetica dei puntatori
Esercizio 4
Scambio di interi.
Tempo: 5 min.
Scrivete un programma che dichiari due puntatori di tipo int di nome px e py, as-
segni al contenuto delle locazioni di memoria puntate i valori 0 e 1, rispettivamente,
e poi scambi i valori in modo che px punti al valore precedentemente puntato da
py e viceversa. Per eseguire lo scambio usate un terzo puntatore a int ausiliario.
Eseguite le stampe appropriate per verificare che lo scambio di valori sia avvenuto
correttamente
*/

#include <stdio.h>

int main() {
    int *px, *py;
    int x = 0, y = 1;

    px = &x;
    py = &y;

    printf("----Before swap:----\n");
    printf("x address: %p\npx point to: %p\nValue pointed %d\n\n", &x, px, *px);
    printf("y address: %p\npy point to: %p\nValue pointed %d\n", &y, py, *py);

    // Swap
    px = &y;
    py = &x;

    printf("\n----After swap:----\n");
    printf("x address: %p\npx point to: %p\nValue pointed %d\n\n", &x, px, *px);
    printf("y address: %p\npy point to: %p\nValue pointed %d\n", &y, py, *py);
    return 0;
}