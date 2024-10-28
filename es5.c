/*
Scrivete un programma che chieda all’utente di inserire una stringa e un carattere.
Il programma memorizza la stringa nella variabile s (di tipo array di char) e il
carattere nella variabile c (di tipo char). Il programma scrive in uscita si' se la
stringa contenuta nella variabile s termina con il carattere contenuto nella variabileQuale costrutto del-
la programmazione
strutturata è natura-
le usare per accedere
all’ultimo carattere
della stringa? E per
stabilire se esso coin-
cide col carattere in
c?
c, e no altrimenti
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[BUFSIZ];
    char c;

    printf("Enter a string:\n");
    fgets(str, BUFSIZ, stdin);

    printf("Enter a character:\n");
    c = getchar();

    if(strlen(str) <= 2) printf("Result: %s\n", str[strlen(str)-1] == c ? "Yes" : "No");
    else {
        printf("Result: %s\n", str[strlen(str)-2] == c ? "Yes" : "No");
    }
    return 0;
}