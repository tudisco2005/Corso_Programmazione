/*
Media aritmetica con lunghezza specificata dall’utente.
Tempo: 15 min.
Modificate la soluzione dell’Esercizio 8 di modo che sia l’utente a decidere, all’i-
nizio del programma, quanti valori double inserire in luogo dei 5 prestabiliti in
quell’esercizio. L’utente deve dunque specificare la dimensione dell’array di double
come numero intero all’inizio del programma. Il programma dichiarerà poi l’array
di double della dimensione appropriata. Aggiungete un controllo dell’errore che
costringa l’utente a reinserire la dimensione dell’array se il valore specificato non è
un intero positivo.
*/

#include <stdio.h>
#include <string.h>

// used a variabile lenght array

int main() {
    int N;
    double sum = 0L;

    do {    
        printf("How many numbers do you want to enter: ");
        scanf("%d", &N);
    } while(N <= 0);

    double values[N];

    for(int i=0; i<N; i++) {
        printf("Enter a number: ");
        scanf("%lf", &values[i]);
        sum += values[i];
    } 


    printf("\nMedia: %lf\n", sum/N);

    return 0;
}