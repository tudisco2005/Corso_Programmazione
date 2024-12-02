/*
Lunghezza media.
Tempo: 20 min.
Scrivete un programma che legga in ingresso delle stringhe inserite dall’utente, e
calcoli la lunghezza media delle stringhe inserite. L’inserimento delle stringhe da
È necessario memorizzare tutte le strin-
ghe inserite dall’uten-
te per calcolarne la
lunghezza media?
parte dell’utente termina quando l’utente preme direttamente invio alla richiesta
di immissione dati.
*/

#include <stdio.h>
#include <string.h>


int main() {
    char str[BUFSIZ];
    int counterChars = 0;
    int counterStr = 0;

    do {
        printf("Enter a str:\n");
        fgets(str, BUFSIZ, stdin);
        counterChars += strlen(str);
        counterStr++;
    } while(str[0] != '\n');
    counterChars -= strlen(str);
    if(counterStr >= 2) counterStr--;

    printf("Len media: %lf\n", (double)counterChars/counterStr);

    return 0;
}