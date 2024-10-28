/*
Modificate la vostra soluzione all’Esercizio 8 in modo che, al termine del calcolo del
M.C.D., il programma visualizzi il numero di operazioni di divisione che ha eseguito.
Usate una variabile intera per tenere traccia del numero di divisioni. Incrementate
di una unità il valore della variabile ad ogni successiva divisione.
*/

#include <stdio.h>

int main() {
    int a, b, aux, counter = 0;
    
    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter a number: ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0) {
        printf("Error, the number entered are not valid\n");
        return -1;
    }

    while(b != 0) {
        aux = b;
        b = a % b;
        counter++;
        a = aux;
    }

    printf("\nM.C.D = %d\n", a);
    printf("Division counter = %d\n", counter);

    return 0;
}