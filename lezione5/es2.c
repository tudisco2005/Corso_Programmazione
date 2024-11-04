/*
Calcolatrice con menu e modifica degli operandi.
Tempo: 15 min.
Migliorate la calcolatrice scritta per l’Esercizio 1 di modo che l’utente possa modi-
ficare il valore degli operandi tramite il menu. In dettaglio, aggiungete al menu la
voce:
0. Inserisci operandi.
ed eliminate la lettura iniziale degli operandi — il programma visualizzerà menu e
prompt direttamente all’avvio. Se l’utente sceglie 0, il programma richiede l’inseri-
mento dei due operandi, e da quel punto in poi il programma eseguirà le operazioni
richieste sui due dati immessi, fino a quando l’utente non si avvarrà nuovamente
dell’opzione 0. Se l’utente sceglie di eseguire una qualunque delle quattro operazioni
prima di aver inserito gli operandi, il programma visualizza un messaggio d’errore,Usate una variabile
apposita per tenere
traccia del fatto che
l’utente abbia o non
abbia ancora impo-
stato i valori degli
operandi. Si tratta di
un secondo esempio
di variabile di stato,
cfr. il riquadro alla
pagina precedente.
e visualizza nuovamente il menu
*/

#include <stdio.h>

enum {EXIT, EDIT, SUM, DIFF, MULTIPLY, DIVISION};

int main() {
    double num1, num2;
    char choice_char;
    int choice_int, entered_nums = 0, ask_again = 0;
    
    while(1) {
        do {
            printf("\nSelect an operation:\n0) Exit\n1) Enter/Edit the numbers\n2) Sum\n3) Diff\n4) Multiply\n5) Division\n-> ");
            choice_char = getchar();
            choice_int = (int) choice_char - 48;
            ask_again = 0;

            if (entered_nums == 0 && choice_int >= SUM) {
                printf("Before the operations enter the numbers\n");
                ask_again = 1;
            }
            if (choice_int < EXIT || choice_int > DIVISION) printf("Operation not valid, retry\n");
        } while(choice_int < EXIT || choice_int > DIVISION || ask_again);

        switch (choice_int) {
            case EDIT:
                printf("\nChange the value %lf to: ", num1);
                scanf("%lf", &num1);
                printf("Change the value %lf to: ", num2);
                scanf("%lf", &num2);
                entered_nums = 1;
                break;
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
        while(getchar() != '\n');
    }

    return 0;
}