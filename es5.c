/*
Funzione clean.
Tempo: 20 min.
Scrivete un programma che chieda all’utente di inserire una stringa, invochi una
funzione che restituisce una copia della stringa privata degli spazi, la visualizzi e
termini. La funzione che elimina gli spazi dalla stringa ha prototipo
void clean(char *s, char *t)
dove il primo parametro rappresenta la stringa da ripulire, e il secondo la stringa
ripulita. In main, invocate la funzione passandole come primo parametro (il nome
di un) array di tipo char inizializzato con una costante stringa, e come secondo
parametro (il nome di un) array di tipo char della medesima dimensione del primo.
*/
#include <stdio.h>
#include <string.h>


void clean(char *s, char *t) {
    int k=0;
    for(int i=0; i<strlen(s); i++) {
        if(s[i] != ' ') {
            t[k] = s[i];
            k++;
        }
    }
    s[k] = '\0';
}

int main() {
    char str1[] = "cia  o ! ";
    char str2[BUFSIZ];

    printf("Prima: %s\n", str1);
    clean(str1, str2);
    printf("Dopo: %s\n", str2);

    return 0;
}