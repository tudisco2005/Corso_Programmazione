/*
LAB. PROG. — LEZIONE 6 5
Esercizio 4
Confronto lessicografico tra stringhe.
Tempo: 25 min.
Scrivete una funzione che permetta di confrontare le stringhe secondo l’ordinamento
lessicografico (cioè quello dei dizionari). Il prototipo è:
int lex(char *s, char *t)
I parametri in ingresso rappresentano le due stringhe da confrontare. La funzione
restituisce un intero positivo se s precede strettamente t nell’ordinamento, un intero
negativo se t precede strettamente t nell’ordinamento, e zero nel caso in cui le due
stringhe siano uguali. Scrivete una procedura main appropriata che permetta di
testare la vostra implementazione
*/

#include <stdio.h>
#include <string.h>

int min(int a, int b) {
    return a<=b ? a:b;
}

int getInput(char *str1) {
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

int lex(char *s, char *t) {
    int common_lenght = min(strlen(s)+1, strlen(t)+1);
    for(int i=0; i<common_lenght; i++) {
        if((int)s[i] < (int)t[i]) return 1;
        if((int)s[i] > (int)t[i]) return -1;
    }
    return 0;
}

int main() {
    char str1[BUFSIZ];
    char str2[BUFSIZ];

    getInput(str1);
    getInput(str2);

    if(lex(str1, str2)>0) printf("La stringa '%s' viene prima della '%s'\n", str1, str2);
    else if(lex(str1, str2)<0) printf("La stringa '%s' viene dopo della '%s'\n", str1, str2);
    else printf("Le stringhe sono uguali\n");

    return 0;
}