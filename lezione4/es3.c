/*
eco di stringhe.
Tempo: 10 min.
Scrivete un programma che chieda all’utente di inserire una frase, e la visualizzi di Usate la funzione
fgets per leggere la
frase inserita dall’u-
tente. Con scanf,
invece, i risultati sono
insoddisfacenti: co-
sa succede se l’utente
include spazi nella
frase? Provate!
nuovo tale e quale.
*/
#include <stdio.h>

int main() {
    char str[BUFSIZ];

    fgets(str, BUFSIZ, stdin);

    printf("\nYou enter:\n");
    printf("%s\n", str);

    return 0;
}