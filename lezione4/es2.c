/*
eggere caratteri con getchar.
Tempo: 5 min.
Scrivete un programma che legga, uno alla volta, due caratteri inseriti dall’utente, li
memorizzi in due variabili c1 e c2 di tipo char, e li visualizzi nuovamente nell’ordine
in cui sono stati inseriti.
*/
#include <stdio.h>

int main() {
    char a,b;

    a=getchar();
    b=getchar();

    printf("\nYou enter:\n");
    printf("%c%c\n", a,b);

    return 0;
}