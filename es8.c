/*
Modificate la vostra soluzione all’Esercizio 7 in modo che il programma si assicuri
che i valori di a e b inseriti dall’utente soddisfino le precondizioni: a, b > 0. Nel
caso ciò non avvenga, visualizzate un appropriato messaggio d’errore per l’utente e
terminate immediatamente l’esecuzione con l’istruzione return -1
*/

#include <stdio.h>

int main() {
    int a, b, aux;
    
    printf("Enter a number: ");
    scanf("%d", &a);

    printf("Enter a number: ");
    scanf("%d", &b);

    if (a <= 0 || b <= 0) {
        printf("Error, the number entered are not valid\n");
        return -1;
    }

    while(b != 0) {
        aux = b;
        b = a % b;
        a = aux;
    }

    printf("M.C.D = %d\n", a);

    return 0;
}