/*
Numeri di Delannoy.
Tempo: 20 min.
Scrivete un programma ricorsivo che legga in ingresso due interi m, n ⩾ 0 e calcoli
e visualizzi il numero di Delannoy D(m, n). Nel caso in cui l’utente inserisca valori
che non soddisfano la condizione m, n ⩾ 0, forzate il reinserimento.
*/

#include <stdio.h>

int delannoy(int m, int n) {
    if(n == 0 || m == 0) return 1;
    return delannoy(m - 1, n) + delannoy(m, n - 1) + delannoy(m - 1, n - 1);
}

int main() {
    int m, n;

    do {
        printf("Inserisci due numeri m, n >= 0: ");
        scanf("%d %d", &m, &n);
    } while(m < 0 || n < 0);

    printf("Il numero di Delannoy D(%d, %d) = %d\n", m, n, delannoy(m, n));
    fflush(stdout);
    return 0;
}