/*
Ordinamento lessicografico delle stringhe.
Tempo: 20 min.

Modificate la soluzione dell’Esercizio 8 di modo che le stringhe inserite dall’utente
siano ordinate secondo l’ordine lessicografico, invece che secondo la loro lunghezza.
Per il confronto lessicografico fra stringhe, riutilizzate la funzione che avete scritto
per risolvere l’Esercizio 4 della Lezione 6.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

int min(int a, int b) {
    return a<=b ? a:b;
}

int lex(char *s, char *t) {
    int common_lenght = min(strlen(s)+1, strlen(t)+1);
    for(int i=0; i<common_lenght; i++) {
        if((int)s[i] < (int)t[i]) return 1;
        if((int)s[i] > (int)t[i]) return -1;
    }
    return 0;
}

void ordina(char **s, int lung) {
    int sorted = 1;
    char *tmp;

    while(sorted) {
        for(int i=0; i<N-1; i++) {
            if(lex(s[i], s[i+1])<0) { // swap
                tmp = s[i+1];
                s[i+1] = s[i];
                s[i] = tmp;
            }
        }

        for(int i=0; i<N-1; i++) {
            if (lex(s[i], s[i+1])<0) {
                sorted = 1;
                break;
            } else sorted = 0;
        }
    }
}

int main() {
    char *list[N];

    for(int i=0; i<N; i++) {
        char *str = (char*) malloc(sizeof(char) * BUFSIZ);
        printf("Inserisci una stringa: ");
        if( fgets (str, BUFSIZ, stdin)==NULL ) {
            printf("Errore in lettura!\n");
            return -1;
        }
        
        /* Sovrascrive \n finale */
        int j=0;
        for (;str[j]!='\n';j++);
        str[j]='\0';
        
        list[i] = str;
    }

    printf("Before:\n");
    for(int i=0; i<N; i++) {
        printf("%d) %s\n", i, list[i]);
    }

    ordina(list, N);

    printf("\nAfter:\n");
    for(int i=0; i<N; i++) {
        printf("%d) %s\n", i, list[i]);
        free(list[i]);
    }

    return 0;
}