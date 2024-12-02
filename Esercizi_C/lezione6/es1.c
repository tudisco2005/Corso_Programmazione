/*
Scrivete un programma che chieda all’utente di inserire una stringa, invochi una
funzione che restituisce una copia della stringa scritta in ordine inverso, la visualizzi
e termini. La funzione che inverte la stringa ha prototipo
void reverse(char *s, char *t)
dove il primo parametro rappresenta la stringa da invertire, e il secondo la stringa
invertita. In main, invocate la funzione passandole come primo parametro (il nome
di un) array di tipo char inizializzato con una costante stringa — ossia la stringa
letta dall’utente — e come secondo parametro (il nome di un) array di tipo char
della medesima dimensione del primo. Un esempio di come potrebbe essere scrittaPrestate attenzione al
fatto che la funzione
fgets include nell’ar-
ray di caratteri let-
ti anche il carattere
'\n' di terminazione
riga: nell’esempio è
incluso il codice ne-
cessario a sovrascrive-
re '\n' con '\0'.
la funzione main del programma è in Fig. 1
*/

#include <stdio.h>
#include <string.h>

void reverse(char* s, char* t) {
    for(int i=1; i<strlen(s)+1; i++) {
        t[i-1] = s[strlen(s)-i];
    }
    t[strlen(s)+1] = '\0';
}

int main(void) {
    void reverse(char*, char*);

    /* BUFSIZ e' una costante definita in stdio.h */
    char str1[BUFSIZ], str2[BUFSIZ];

    printf("Inserisci una stringa: ");
    if( fgets (str1, BUFSIZ, stdin)==NULL ) {
        printf("Errore in lettura!\n");
        return -1;
    }
    /* Sovrascrive \n finale */
    int i=0;
    for (;str1[i]!='\n';i++);
    str1[i]='\0';

    reverse(str1, str2);
    printf("La stringa al contrario e': %s\n", str2);

    return 0;
}