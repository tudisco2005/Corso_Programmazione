/*
Visualizzare caratteri e stringhe con printf.
Tempo: 5 min.
Scrivete un programma che dichiari una variabile str di tipo array di char e una
variabile c di tipo char, e assegni loro come valori, rispettivamente, la costante
stringa "Pippo" e la costante carattere 'Z'. Il programma, prima di terminare,
deve visualizzare il contenuto delle variabili str e c. 
*/
#include <stdio.h>

int main() {
    char str[] = "Pippo";
    char c = 'Z';

    printf("str: %s\n", str);
    printf("c: %c\n", c);

    return 0;
}