/*
l signor Pignolino.
Tempo: 35 min.
Il signor Pignolino è pensionato. Egli esce di casa ogni mattina, ma solo a condizione
che non piova e che le previsioni metereologiche per la giornata siano buone. Nel
caso in cui decida di uscire, se il giorno del mese è pari (ad esempio, è il 20 di
febbraio, o di marzo, etc.), si reca ai giardini pubblici, portando con sé un libro;
altrimenti, si reca al Caffé, portandosi dietro il suo diario personale invece di un
libro. Quanto detto vale a meno che non sia domenica, giorno in cui il signor
Pignolino va invariabilmente a far visita alla sua cara amica signora Precisina,
avendo l’accortezza di prendere un ombrello nel caso in cui piova o le condizioni
metereologiche non siano buone, o un parasole altrimenti.
Si scriva un programma che rivolga al signor Pignolino un certo numero di do-
mande, tenga traccia delle sue risposte per mezzo di variabili intere, e produca
in uscita una descrizione accurata del comportamento del signor Pignolino per la
giornata. Il signor Pignolino è impersonato dall’utente. Si assuma che le risposte
del signor Pignolino siano solo del tipo Sì/No, codificate dai caratteri S e N, rispet-
tivamente. Se la risposta a una qualsiasi delle domande non è S o N, il programma
termina con un messaggio d’errore. Se invece tutte le risposte del signor Pignolino
sono state acquisite correttamente, il programma deve produrre in uscita, prima
di terminare, una e una sola fra le frasi seguenti, quella che riflette esattamente le
risposte fornite da Pignolino:

• Il signor Pignolino oggi non e' uscito.
LAB. PROG. — LEZIONE 3 9
• Il signor Pignolino oggi e' uscito per recarsi ai giardini pubblici. Ha portato con se' un libro.
• Il signor Pignolino oggi e' uscito per recarsi al Caffe'. Ha portato con se' il suo diario.
• Il signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un ombrello.
• Il signor Pignolino oggi e' uscito per recarsi dalla signora Precisina. Ha portato con se' un parasole
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
    do {
        printf("Is it raining today? (S/N): ");
        scanf(" %c", &weather);
        if (weather != 'S' && weather != 'N') printf("Invalid input. Please enter S for Yes or N for No: ");
    } while (weather != 'S' && weather != 'N');

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
