/*
Eco iterato.
Tempo: 25 min.
(1) Scrivete un programma che legga in ingresso una stringa inserita dall’utente, e
la riscriva tale e quale sulla console. L’esecuzione deve continuare in questo modo
fino a che l’utente non prema subito invio senza scrivere altro.
(2) Modificate poi il programma in modo da produrre in uscita, prima della termi-
nazione, il numero complessivo di caratteri inseriti dall’utente durante l’esecuzione.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[BUFSIZ];
    int counter = 0;

    do {
        printf("Enter a str:\n");
        fgets(str, BUFSIZ, stdin);
        counter += strlen(str);
        printf("You entered a string with len %d: %s\n", strlen(str), str);
    } while(str[0] != '\n');

    printf("You entered a total of %d characters\n", counter-1);

    return 0;
}