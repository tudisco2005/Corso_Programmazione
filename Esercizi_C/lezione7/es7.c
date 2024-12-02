/*
Occorrenze di un carattere in una stringa: implementazione ricorsiva.
Tempo: 15 min.
Scrivete una funzione di prototipo int occ(char *, char) che accetti in ingresso
una stringa e un carattere, e restituisca il numero di occorrenze del carattere nella
stringa. L’implementazione della funzione deve essere ricorsiva. Per convenzione,
se il puntatore ricevuto dalla funzione è NULL, il numero di occorrenze di qualunque
carattere nella stringa è -1. Scrivete una funzione main che vi permetta di testare
la vostra implementazione della funzione occ.
*/

#include <stdio.h>

int occ(char *str, char n) {
    if(str == NULL) return -1;
    if(*str == '\0') return 0;
    if(*str == n) return 1 + occ(str + 1, n);
    return occ(str + 1, n);
}

int main() {
    char s[] = "ciiiaioa";
    printf("Il numero di occorrenze del carattere 'i' nella stringa(\"%s\") = %d\n", s, occ(s, 'i'));
    printf("Il numero di occorrenze del carattere 'a' nella stringa(\"%s\") = %d\n", s, occ(s, 'a'));
    fflush(stdout);
    return 0;
}
