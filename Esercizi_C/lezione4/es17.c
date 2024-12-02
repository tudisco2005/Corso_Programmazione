/*
Frequenza di più caratteri.
Tempo: 20 min.
Modificate la vostra soluzione dell’Esercizio 16 per far sì che il programma, dopo
aver chiesto all’utente l’inserimento del carattere di cui calcolare la frequenza e aver
visualizzato il risultato, iteri in modo da dare la possibilità all’utente di ripetere
il calcolo per un nuovo carattere. L’iterazione prosegue fino a quando l’utente
digita direttamente invio alla richiesta di immissione del carattere, nel qual caso il
programma termina.
*/

#include <stdio.h>
#include <string.h>


int main() {
    char str[BUFSIZ];
    char chr;

    printf("Enter a str: ");
    fgets(str, BUFSIZ, stdin);
    do {
        int times = 0;
        printf("Enter a char: ");
        chr = getchar();
        getchar();

        if(chr != '\n') {
            for (int i = 0; i < strlen(str)-1; i++) {
                if(str[i] == chr) times++;
            }

            printf("The char '%c' occures %d times: %lf\n", chr, times, (double)times/(strlen(str)-1));
        }
    } while (chr != '\n');
    

    return 0;
}