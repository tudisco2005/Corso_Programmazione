/*
Funzione equals.
Tempo: 15 min.
Scrivete una funzione di prototipo
int equals(char *s, char *t)
che accetti in ingresso due stringhe, e restituisca in uscita un intero di valore non
negativo nel caso le due stringhe siano uguali, e nullo altrimenti. Scrivete una
funzione main atta a testare adeguatamente la vostra funzione.
*/

#include <stdio.h>
#include <string.h>

void getInput(char *str1) {
    printf("Inserisci una stringa: ");
    if( fgets (str1, BUFSIZ, stdin)==NULL ) {
        printf("Errore in lettura!\n");
        return -1;
    }
    /* Sovrascrive \n finale */
    int i=0;
    for (;str1[i]!='\n';i++);
    str1[i]='\0';
}

int equals(char *s, char *t) {
    if(strlen(s) != strlen(t)) return 0;
    else {
        for(int i=0; i<strlen(s); i++){
            if(s[i] != t[i]) return 0;
        }
    }
    return 1;
}

int main(void) {
    /* BUFSIZ e' una costante definita in stdio.h */
    char str1[BUFSIZ], str2[BUFSIZ];

    getInput(str1);
    getInput(str2);

    if(equals(str1, str2)) printf("Le stringhe sono uguali\n");
    else printf("Le stringhe NON sono uguali\n");
    
    return 0;
}