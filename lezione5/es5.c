/*
Esercizio 5
Scambio di stringhe.
Tempo: 5 min.
Ripetete l’esercizio precedente usando puntatori a char (inizializzati in modo da
puntare a stringhe di caratteri) in luogo di puntatori a int. Dichiarate le stringhe di
caratteri direttamente nel codice, senza leggerle da tastiera. Per esempio, dichiarate
e inizializzate una stringa in questo modo:
char s[] = "Galileo Galilei";
*/

#include <stdio.h>

int main() {
    char *a = "Galileo";
    char *b = "Galilei";

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    printf("----swap----\n");

    char *temp;
    temp = a;
    a = b;
    b = temp;

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    return 0;
}