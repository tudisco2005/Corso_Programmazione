/*
Tempo: 15 min.
Scrivete un programma che legga in ingresso una stringa inserita dall’utente, legga
inoltre un carattere inserito dall’utente, e calcoli la frequenza del carattere all’inter-
no della stringa. La frequenza è definita come il rapporto (tipo double o float) fra
il numero di occorrenze del carattere all’interno della stringa e la lunghezza della
stringa.
*/

#include <stdio.h>
#include <string.h>


int main() {
    char str[BUFSIZ];
    char chr;
    int times = 0;

    printf("Enter a str: ");
    fgets(str, BUFSIZ, stdin);
    printf("Enter a char: ");
    chr = getchar();

    for (int i = 0; i < strlen(str)-1; i++) {
        if(str[i] == chr) times++;
    }

    printf("The char '%c' occures %d times: %lf\n", chr, times, (double)times/(strlen(str)-1));

    return 0;
}