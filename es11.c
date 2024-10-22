/*
Il matematico francese Gabriel Lamé (1795–1870) dimostrò il fatto seguente.
Proposizione
Sia n > 0 un intero, e siano a > b > 0 interi tali che l’algoritmo euclideo della
Figura 3 applicato ad a e b esegua esattamente n divisioni. Se a è il minimo
intero che soddisfa tali condizioni, si ha
a = Fn+2
b = Fn+1,
dove Fn denota la successione di Fibonacci.
Usando i programmi che avete sviluppato negli Esercizi 10 e 9, verificate la proposi-
zione di Lamé in qualche caso concreto. Per esempio, la Tabella 2 riporta il numero
di divisioni eseguito dall’algoritmo euclideo per 8 ⩾ a ⩾ b > 0. La vostra soluzione
dell’Esercizio 9 dovrebbe produrre valori identici. Ora notate che la prima coppia
(a, b) che richieda 4 divisioni è (8, 5) — e infatti, dalla Tabella 1 si vede che F6 = 8
ed F5 = 5, in accordo con la proposizione di Lamé. Provate con almeno altri due
valori di n, uno più piccolo e uno più grande di 4.
*/

#include <stdio.h>
#include <stdlib.h>

// Funzione per calcolare la n-esima Fibonacci
int fibonacci(int n) {
    int f_i = 1, f_prec = 1;
    for (int i = 3; i <= n; i++) {
        int aux = f_i;
        f_i += f_prec;
        f_prec = aux;
    }
    return f_i;
}

// Funzione per l'algoritmo euclideo
int euclidean_algorithm(int a, int b) {
    int counter = 0;
    while(b != 0) {
        int aux = b;
        b = a % b;
        counter++;
        a = aux;
    }
    return counter;
}

int main(void) {
    int n;
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error: Please enter a positive integer.\n");
        return 1;
    }

    int fib_n_plus_2 = fibonacci(n+2);
    int fib_n_plus_1 = fibonacci(n+1);

    int divisions = euclidean_algorithm(fib_n_plus_2, fib_n_plus_1);

    printf("\nLamé's Proposition Verification:\n");
    printf("For n = %d:\n", n);
    printf("a = %d (F%d)\n", fib_n_plus_2, n+2);
    printf("b = %d (F%d)\n", fib_n_plus_1, n+1);
    printf("Number of divisions: %d\n", divisions);
    printf("Does it match n? %s\n", divisions == n ? "Yes" : "No");

    return 0;
}
