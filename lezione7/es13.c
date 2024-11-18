/*
Successioni maschio-femmina di Hofstadter.
Tempo: 30 min.
Si consideri la coppia di successioni definite da
F(n) = n − M(F(n − 1)), (3)
M(n) = n − F(M(n − 1)), (4)
con valori iniziali
F(0) = 1 , (5)
M(0) = 0 . (6)
Si tratta delle successioni maschio-femmina di Hofstadter. Per maggiori informazioni si veda, ad esempio, questa pagina di Wolfram’s MatWorld.
I primi dieci numeri della sequenza maschio M(n) sono 0, 0, 1, 2, 2, 3, 4, 4, 5, 6. I
primi dieci numeri della sequenza femmina F(n) sono 1, 1, 2, 2, 3, 3, 4, 5, 5, 6.
Si implementi, secondo le seguenti specifiche, un programma per calcolare i primi
n + 1 numeri delle sequenze F(n) e M(n), per un valore n inserito dall’utente.
(a) Il programma chiede all’utente di inserire un numero intero n ⩾ 0, verificando la correttezza dell’input. Se n < 0 il programma forza il reinserimento.
(b) Il programma visualizza in output i primi n+ 1 numeri delle sequenze F(n)
e M(n). Ad esempio, per n = 4 l’output del programma sarà:
n F(n) M(n)
0 1 0
1 1 0
2 2 1
3 2 2
4 3 2
*/

#include <stdio.h>

int m(int);
int f(int);

int m(int n) {
    if(n == 0) return 0;
    return n - f(m(n-1));
}

int f(int n) {
    if(n == 0) return 1;
    return n - m(f(n-1));
}

int main() {
    int n;

    do {
        printf("Inserisci un numero n >= 0: ");
        scanf("%d", &n);
    } while(n < 0);

    printf("n\tf(n)\tm(n)\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\n", i, f(i), m(i));
    }

    fflush(stdout);
    return 0;
}