/*
Tabulazione dei numeri di Catalan.
Tempo: 25 min.
Scrivete un programma che legga in ingresso un intero n ⩾ 0 e calcoli e visualizzi la
sequenza C(0), C(1), . . . , C(n) di numeri di Catalan. Per esempio, nel caso in cui
n = 9 l’output del vostro programma dovrebbe essere:
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862.
Riutilizzate la funzione ricorsiva scritta per risolvere l’Esercizio 8.
*/

#include <stdio.h>

int catalan(int n) {
    if (n == 0) return 1;
    return (2*(2*n - 1) * catalan(n - 1)) / (n + 1);
}

int main() {
    int n;

    do {
        printf("Inserisci un numero n >= 0: ");
        scanf("%d", &n);
    } while(n < 0);

    for(int i=0; i<n; i++) printf("%d, ",catalan(i));
    fflush(stdout);
    return 0;
}