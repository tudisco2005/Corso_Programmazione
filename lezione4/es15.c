/*
Lunghezza massima.
Tempo: 15 min.
Scrivete un programma che legga in ingresso delle stringhe inserite dall’utente, e
calcoli la lunghezza massima fra le lunghezze delle stringhe inserite. L’inserimento
delle stringhe da parte dell’utente termina quando l’utente preme direttamente
invio alla richiesta di immissione dati.
*/

#include <stdio.h>
#include <string.h>


int main() {
    char str[BUFSIZ];
    int maxlen = 0;

    do {
        printf("Enter a str:\n");
        fgets(str, BUFSIZ, stdin);
        if(maxlen < strlen(str)) maxlen = strlen(str);
    } while(str[0] != '\n');

    printf("\nLen max: %d\n", maxlen);

    return 0;
}