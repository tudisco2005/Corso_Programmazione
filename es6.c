/*
Funzione clean parametrica.
Tempo: 10 min.
Scrivete un programma che chieda all’utente di inserire una stringa, invochi una Riutilizzate il codice
che avete scritto per
l’Esercizio 5.
funzione che restituisce una copia della stringa privata di tutte le occorrenze di un
carattere passato in argomento alla funzione, la visualizzi e termini. La funzione
che elimina le occorrenze del carattere dalla stringa ha prototipo
void clean(char *s, char *t, char c)
dove il primo parametro rappresenta la stringa da ripulire, il secondo la stringa
ripulita, e il terzo il carattere le cui occorrenze sono da eliminare. In main, invocate
la funzione passandole come primo parametro (il nome di un) array di tipo char
inizializzato con una costante stringa, e come secondo parametro (il nome di un)
array di tipo char della medesima dimensione del primo
*/

#include <stdio.h>
#include <string.h>

void clean(char *s, char *t, char c) {
    int k=0;
    for(int i=0; i<strlen(s); i++) {
        if(s[i] != c) {
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
    clean(str1, str2, ' ');
    printf("Dopo: %s\n", str2);

    return 0;
}