/*
Scrivete un programma che legga in ingresso una stringa inserite dall’utente, e mo-
difichi la stringa letta convertendo tutti i suoi caratteri in maiuscola. Il programma
visualizza poi la stringa convertita in maiuscola e termina
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[BUFSIZ];
    char chr;

    printf("Enter a str: ");
    fgets(str, BUFSIZ, stdin);

    printf("Upper case: ");
    for(int i=0; i<strlen(str); i++) {
        printf("%c", toupper(str[i]));
    }
    
    return 0;
}