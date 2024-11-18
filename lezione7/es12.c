/*

Numeri di Bell.
Tempo: 25 min.
Scrivete una funzione int bell(int n) che, dato in ingresso un numero naturale
n ⩾ 0, restituisca il numero di Bell B(n). Per implementare int bell(int n)
ricorsivamente, scrivete due funzioni ausiliarie. La prima, int fatt(int n), restituisce il fattoriale del numero naturale in ingresso n ⩾ 0, ed è implementata
ricorsivamente. La seconda, int binom(n,k), restituisce il coefficiente binomiale n
k

, dati due naturali in ingresso n ⩾ k ⩾ 0, ed è implementata usando i
8 LAB. PROG. — LEZIONE 7
fatt(int n). Scrivete una procedura main che chieda all’utente di inserire un intero n ⩾ 0 e visualizzi sul terminale il numero di Bell B(n). Forzate il reinserimento
se l’intero n digitato dall’utente non soddisfa la condizione n ⩾ 0.
*/

#include <stdio.h>

int fatt(int n) {
    if(n == 0) return 1;
    return n * fatt(n - 1);
}

int binom(int n, int k) {
    return fatt(n) / (fatt(k) * fatt(n - k));
}

int bell(int n) {
    if(n == 0) return 1;
    int sum = 0;
    for(int k=0; k<n; k++) {
        sum += binom(n - 1, k) * bell(k);
    }
    return sum;
}

int main() {
    int n;

    do {
        printf("Inserisci un numero n >= 0: ");
        scanf("%d", &n);
    } while(n < 0);

    printf("B(%d) = %d\n", n, bell(n));

    fflush(stdout);
    return 0;
}