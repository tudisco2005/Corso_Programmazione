/*
Tabulazione dei numeri di Delannoy.
Tempo: 25 min.
Scrivete un programma che legga in ingresso due interi m, n ⩾ 0 e calcoli e visualizzi
una tabella rettangolare di dimensioni m × n il cui elemento di posto (i, j) sia il
numero di Delannoy D(i, j). Per esempio, nel caso in cui m = n = 9 l’output del
vostro programma dovrebbe collimare con quello mostrato in Figura 4. Riutilizzate
la funzione ricorsiva scritta per risolvere l’Esercizio 10.
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


    for(int i=0; i<=m; i++) {
        for(int j=0; j<=m; j++) {
            printf("%d\t", delannoy(i, j));
        }
        printf("\n");
    }

    fflush(stdout);
    return 0;
}