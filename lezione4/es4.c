/*
Lunghezza delle stringhe.
Tempo: 10 min.
Scrivete un programma che chieda all’utente di inserire una stringa, e visualizzi la
lunghezza della stringa immessa dall’utente
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[BUFSIZ];

    fgets(str, BUFSIZ, stdin);

    printf("strlen(without \\0): %d\n", strlen(str));
    return 0;
}