/*
Tempo: 25 min.
Scrivete un programma che chieda all’utente di inserire una stringa, invochi unaRiutilizzate il codice
che avete scritto per
l’Esercizio 6.
funzione che restituisce una copia della stringa privata di tutte le occorrenze degli
elementi di un insieme di caratteri passato in argomento alla funzione, la visualizzi
e termini. La funzione che elimina le occorrenze dei caratteri dalla stringa ha
prototipo
void clean(char *s, char *t, char *u)
dove il primo parametro rappresenta la stringa da ripulire, il secondo la stringa
ripulita, e il terzo una stringa i cui caratteri sono quelli le cui occorrenze sono da
eliminare (escluso il \0 di terminazione di u). Per esempio, se u punta a "A x", dalla
stringa s saranno eliminate tutte le occorrenze dei caratteri 'A', '' (=spazio) e 'x'.
Nel main, invocate la funzione passandole come primo parametro (il nome di un)
array di tipo char inizializzato con una costante stringa, come secondo parametro
(il nome di un) array di tipo char della medesima dimensione del primo e come
terzo parametro (il nome di un) array di tipo char inizializzato con una costante
stringa.
*/

#include <stdio.h>
#include <string.h>

void clean(char *s, char *t, char *u) {
    int k=0;
    int flag=0;

    for(int i=0; i<strlen(s); i++) {
        flag=1;
        for(int j=0; j<strlen(u); j++) {
            if(s[i] == u[j]) {
                flag = 0;
            }
        }
        if(flag){
            t[k] = s[i];
            k++;
        }
    }
    s[k] = '\0';
}

int main() {
    char str1[] = "cia  o ! ";
    char str2[BUFSIZ];

    char toRemove[] = "abc ";

    printf("Prima: %s\n", str1);
    clean(str1, str2, toRemove);
    printf("Dopo: %s\n", str2);

    return 0;
}