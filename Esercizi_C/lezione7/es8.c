/*
Numeri di Catalan.
Tempo: 20 min.
Scrivete un programma ricorsivo che legga in ingresso un intero n ⩾ 0 e calcoli e
visualizzi il numero di Catalan C(n). Nel caso in cui l’utente inserisca un valore
che non soddisfa la condizione n ⩾ 0, forzate il reinserimento

I numeri di Catalan
I numeri di Catalan prendono il nome dal matematico belga Eugène Charles
Catalan (1814–1894). Essi si denotano con C(n), dove n è un intero ⩾ 0, e
contano il numero di cammini in una griglia quadrata di dimensione n × n
che partono dall’angolo sud-ovest e arrivano all’angolo nord-est senza mai oltrepassare la diagonale sud-ovest/nord-est della griglia, impiegando solo passi
verso nord ed est. Si veda la Figura 2.
I numeri di Catalan soddisfano la relazione ricorsiva:
C(n) = (2(2n − 1)C(n − 1)) / (n + 1)
con condizione iniziale
C(0) = 1.
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

    printf("Il numero di Catalan C(%d) = %d\n", n, catalan(n));
    fflush(stdout);
    return 0;
}