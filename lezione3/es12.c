/*
Il signor Pignolino interrogato con insistenza.
Tempo: 15 min.
Modificate il programma che avete scritto per risolvere l’Esercizio 12 di modo che,
nel caso in cui Pignolino risponda a un domanda con un carattere diverso da S e N,
il programma, invece di terminare con errore, ponga nuovamente la stessa domanda
fino ad ottenere una risposta nel formato corretto. Per il resto il comportamento
del programma è invariato.
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int month;
    int day;
    char year[5];
    char weather;
    bool isSunday;

    // Ask user for date
    printf("Enter today's date (MM/DD/YYYY): ");
    scanf("%d/%d/%s", &month, &day, year);

    // Validate date
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date. Please enter a valid date (MM/DD/YYYY).\n");
        return 1;
    }

    // Ask user about weather conditions

    printf("Is it raining today? (S/N): ");
    scanf(" %c", &weather);
    if (weather != 'S' && weather != 'N') { 
        printf("Invalid input"); 
        return 1;
    }


    // Determine if it's Sunday
    isSunday = (day == 7 || day == 14 || day == 21 || day == 28); // Assuming week starts on Monday

    // Print result based on conditions
    if (!isSunday && weather == 'N') {
        printf("Il signor Pignolino oggi e' uscito per recarsi ai giardini pubblici. Ha portato con se' un libro.\n");
    } else if (!isSunday && weather == 'S') {
        printf("Il signor Pignolino oggi e' uscito per recarsi al Caffe'. Ha portato con se' il suo diario.\n");
    } else if (weather == 'S') {
        printf("Il signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un ombrello.\n");
    } else {
        printf("Il signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un parasole\n");
    }

    return 0;
}
