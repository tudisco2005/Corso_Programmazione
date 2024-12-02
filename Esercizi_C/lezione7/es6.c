/*
Lunghezza di una stringa: implementazione ricorsiva.
Tempo: 15 min.
Scrivete una funzione di prototipo int lung(char *) che accetti in ingresso una
stringa e ne restituisca la lunghezza. L’implementazione della funzione deve essere
ricorsiva. Per convenzione, se il puntatore ricevuto dalla funzione è NULL, la lun- Suggerimento. La
lunghezza di una
stringa della forma
cs, dove c è un carattere ed s una stringa,
è pari alla lunghezza
di s più 1.
ghezza restituita è -1. Se lunghezza della stringa vuota—cioè, di un array di char
il cui primo carattere sia \0—è zero. Scrivete una funzione main che vi permetta
di testare la vostra implementazione della funzione lung.
La codifica iterativa della funzione per il calcolo della lunghezza di una stringa,
che avete già scritto in esercizi precedenti, è semplice come la versione ricorsiva
e risulta molto più efficiente in esecuzione. L’Esercizio 6 ha quindi il solo
scopo di farvi prendere dimestichezza con le implementazioni ricorsive. Ciò
vale anche per altri esercizi di questa lezione.
*/

#include <stdio.h>

int lung(char *str){
    if(str == NULL) return -1;
    if(*str == '\0') return 0;
    return 1 + lung(str + 1);
}

int main() {
    char s[] = "ciao";
    printf("La lunghezza della stringa(\"%s\") = %d\n", s, lung(s));
    fflush(stdout);
    return 0;
}
