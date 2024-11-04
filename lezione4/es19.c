/*
Cercare una sottostringa.
Tempo: 30 min.
Scrivete un programma che legga in ingresso una stringa inserite dall’utente, ne
legga una seconda, e stampi si se la seconda stringa compare come sottostringa
della prima stringa, e no altrimenti. Si intende qui per sottostringa una qualunque
sottosequenza di caratteri consecutivi. Per esempio, "Pinco P" è sottostringa di
"Il mio amico Pinco Pallino", mentre "inco p", "incoP" e "Il mio amico
Pinco Pallino?" non lo sono.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[BUFSIZ];
    char search[BUFSIZ];
    char chr;
    int found = 0;

    printf("Enter a str: ");
    fgets(str, BUFSIZ, stdin);

    printf("Enter the search: ");
    fgets(search, BUFSIZ, stdin);
    
    for (int j = 0; j < strlen(str); j++) {
        for (int i = 0; i < strlen(search)-1; i++){
            found = 1;
            if(j+i > strlen(str)) {
                printf("Out of str\n");
                break;
            }
            
            if(str[j+i] != search[i]) {
                found = 0;
                break;
            }
        }
        if(found) break;
    }
    
    printf("the search is %s in the string\n", found ? "present" : "is not present");

    return 0;
}