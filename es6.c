/*
algoritmo euclideo con le divisioni per MCD.
Tempo: 20 min.
La Figura 3 mostra lo pseudocodice dell’algoritmo euclideo basato sulle divisioni
successive. Scrivete il codice C corrispondente, assumendo che a e b siano varia-
bili intere il cui valore è impostato all’inizio del programma tramite istruzioni di
assegnamento; per esempio, int a=100; e int b=46; .
Input : a, b > 0
Output : m.c.d.(a, b)
while (b̸ = 0)
aux := b
b := a mod b
a := aux
return a
*/

#include <stdio.h>

int main() {
    int a = 100, b = 46, aux;
    while(b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }

    printf("M.C.D = %d\n", a);

    return 0;
}