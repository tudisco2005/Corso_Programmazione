/*
Scrivete un programma che chieda all’utente di inserire un nome proprio di persona,Questo esercizio si
risolve rapidamente
riutilizzando il codice
che hai scritto per
l’Esercizio 5.
e tenti di dedurre automaticamente se trattasi di un nome maschile o femminile. A
tale scopo, adottate la seguente strategia: se il nome inserito termina per a o per
e, assumete che il genere sia femminile; se invece termina per o o per i, assumete
che sia maschile; altrimenti, accettate la sconfitta e dichiarate di non saper trarre
conclusioni.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[BUFSIZ];

    do {
        printf("Enter your name:\n");
        fgets(str, BUFSIZ, stdin);
    } while(str[0] == '\n');

    printf("\nGuess:\n");
    if(str[strlen(str)-2] == 'a' || str[strlen(str)-2] == 'e') {
        printf("Female\n");
    } else if(str[strlen(str)-2] == 'i' || str[strlen(str)-2] == 'o') {
        printf("Male\n");
    } else printf("I dont know\n");

    return 0;
}