/*
Calcolatrice usa e getta.
Tempo: 20 min.
Scrivete un programma secondo le specifiche seguenti.
(1) All’avvio, il programma chiede all’utente di inserire due valori reali (tipo
double).
(2) Acquisiti i due operandi, il programma chiede all’utente se voglia eseguire
una somma, una sottrazione, una moltiplicazione, o una divisione.
(3) L’utente inserisce uno fra gli interi 1, 2, 3, e 4 per indicare la sua scelta.
(4) Acquisita la scelta dell’utente, il programma esegue l’operazione richiesta, Osservate: l’analisi
dei dati inseriti dal-
l’utente si basa sul
costrutto selezione. È
necessario usare il co-
strutto iterazione in
questo programma?
visualizza il risultato, e termina.
*/

#include <stdio.h>

enum {EXIT, SUM, DIFF, MULTIPLY, DIVISION};

int main() {
    double num1, num2;
    int choice;
    
    while(1) {
        printf("Enter a number: ");
        scanf("%lf", &num1);
        printf("Enter a number: ");
        scanf("%lf", &num2);

        do {
            printf("\nSelect an operation:\n0) Exit\n1) Sum\n2) Diff\n3) Multiply\n4) Division\n-> ");
            scanf("%d", &choice);
            if (choice < EXIT || choice > DIVISION) printf("Operation not valid, retry\n");
        } while(choice < EXIT || choice > DIVISION);

        switch (choice) {
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