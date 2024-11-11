/*
Funzione palindroma.
Tempo: 30 min.
Scrivete una funzione di prototipo
int palindroma(char *s)
che accetti in ingresso una stringa, e restituisca in uscita un intero di valore non
negativo nel caso la stringa sia palindroma, e nullo altrimenti. Scrivete una prima
versione che utilizzi le funzioni reverse e equals degli Esercizi 1 e 2. Scrivete una
funzione main atta a testare adeguatamente la vostra funzione. Scrivete poi una
seconda implementazione della funzione palindroma che utilizzi solo la stringa sQuesta seconda im-
plementazione è meno
facile da scrivere, e
può sembrare una so-
luzione meno elegante
rispetto alla prima:
osserverete, tuttavia,
che essa è senz’altro
la più efficiente del-
le due dal punto di
vista dell’uso delle
risorse fisiche a di-
sposizione (spazio in
memoria, tempo di
calcolo).
passata in argomento, senza invocare funzioni ausiliarie e senza allocare memoria
per una copia di s.
*/

#include <stdio.h>
#include <string.h>

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


void reverse(char* s, char* t) {
    for(int i=1; i<strlen(s)+1; i++) {
        t[i-1] = s[strlen(s)-i];
    }
    t[strlen(s)+1] = '\0';
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

int isPalindrome(char *s) {
    for(int i=0; i<strlen(s); i++) {
        if(s[i] != s[strlen(s)-1-i]) return 0; 
    }
    return 1;
}

int main() {
    char str1[BUFSIZ];
    char temp[BUFSIZ];


    getInput(str1);

    //prima parte
    reverse(str1, temp);
    if(equals(str1,temp)) printf("La stringa e' palindroma\n");
    else printf("La stringa NON e' palindroma\n");

    printf("\n\n");

    // seconda parte
    if(isPalindrome(str1)) printf("La stringa e' palindroma\n");
    else printf("La stringa NON e' palindroma\n");


    return 0;
}