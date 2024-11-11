/*
Ordinamento delle stringhe per lunghezza.
Tempo: 40 min.
Scrivete un programma che chieda all’utente di inserire 5 stringhe, e le memorizzi
in un array di puntatori a char appropriatamente dimensionato. Il programma
chiama poi una funzione di prototipo
void ordina(char **s, int lung)
il cui primo parametro rappresenta l’array di puntatori a char, e il cui secondo
parametro rappresenta il numero di stringhe puntate dagli elementi dell’array (in
questo esempio, 5). La funzione ordina l’array di stringhe in ordine non decrescente
di lunghezza. Scrivete una funzione ausiliaria per il calcolo della lunghezza di una
stringa. Come algoritmo di ordinamento usate Bubble Sort, che avete implementato
nell’Esercizio 11 della Lezione 4.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 5

void ordina(char **s, int lung) {
    int sorted = 1;
    char *tmp;

    while(sorted) {
        for(int i=0; i<N-1; i++) {
            if(strlen(s[i]) > strlen(s[i+1])) { // swap
                tmp = s[i+1];
                s[i+1] = s[i];
                s[i] = tmp;
            }
        }

        for(int i=0; i<N-1; i++) {
            if (strlen(s[i]) > strlen(s[i+1])) {
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