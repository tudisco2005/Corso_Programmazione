/*
Esercizio 1
Calcolatrice con menu.
Tempo: 20 min.
Scrivete un programma che chieda all’utente di inserire due numeri (operandi) di
tipo double. Il programma visualizza poi il menu seguente. I menu si codificano
tramite il costrutto
selezione della pro-
grammazione strut-
turata. È convenien-
te usare l’istruzione
switch invece di una
serie di if-else-if,
quando le scelte sono
più di un paio.
1. Addizione.
2. Sottrazione.
3. Moltiplicazione.
4. Divisione.
5. Esci.
>
dove > è un “prompt” che indica all’utente che la macchina è in attesa dell’input
dell’utente. L’utente inserisce una scelta, che il programma acquisisce come dato di
tipo char. Se la scelta è inesistente, il programma stampa un messaggio d’errore, e
visualizza nuovamente il menu. Se la scelta è 5, il programma termina. Se la scelta
è 1, 2 o 3, il programma stampa il risultato dell’operazione corrispondente applicata
agli operandi, e visualizza nuovamente il menu. Se la scelta è 4 e il divisore è nullo,
il programma stampa un messaggio d’errore, e visualizza nuovamente il menu; se
il divisore non è nullo, stampa il risultato della divisione applicata agli operandi, e
visualizza nuovamente il menu.
*/

#include <stdio.h>

enum {EXIT, SUM, DIFF, MULTIPLY, DIVISION};

int main() {
    double num1, num2;
    char choice_char;
    int choice_int;
    
    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter a number: ");
    scanf("%lf", &num2);
    
    while(1) {
        while(getchar() != '\n');
        do {
            printf("\nSelect an operation:\n0) Exit\n1) Sum\n2) Diff\n3) Multiply\n4) Division\n-> ");
            choice_char = getchar();
            choice_int = (int) choice_char - 48;

            if (choice_int < EXIT || choice_int > DIVISION) printf("Operation not valid, retry\n");
        } while(choice_int < EXIT || choice_int > DIVISION);

        switch (choice_int) {
            case SUM:
                printf("SUM: %lf + %lf = %lf\n", num1, num2, num1+num2);
                break;
            case DIFF:
                printf("Diff: %lf - %lf = %lf\n", num1, num2, num1-num2);
                break;
            case MULTIPLY:
                printf("Multiply: %lf * %lf = %lf\n", num1, num2, num1*num2);
                break;
            case DIVISION:
                if (num2 == 0) printf("Error, Division by zero\n");
                else printf("Division: %lf / %lf = %lf\n", num1, num2, num1/num2);
                break;
            
            case EXIT:
                return 0;
        }
        printf("\n");
    }

    return 0;
}