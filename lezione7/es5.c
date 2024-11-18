/*
Leggere una frase e creare una struttura dati per contenerla.
Tempo: 10 min.
Si scriva un programma che chieda all’utente quante parole voglia inserire. Tali
parole (senza spazi o caratteri speciali) dovranno essere inserite in un array di
puntatori a stringhe di dimensione N = 20. Per ciascuna di tale parole, inserite
dall’utente, si allochi dinamicamente una nuova stringa della dimensione esatta
della parola inserita. Stampare a schermo la frase ottenuta. Completate per farlo
il codice di Fig. 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
#define MAX_WORD_LENGTH 50

int main() {
    // Chiede all'utente quanti parole vuole inserire
    int numParole, i;
    // Alloca staticamente un array di puntatori a stringhe di dimensione N
    char *parole[N];
    // Buffer per la lettura di ogni parola
    char buffer[MAX_WORD_LENGTH];

    printf("Inserisci il numero di parole (massimo %d): ", N);
    scanf("%d", &numParole);

    // Verifica che il numero di parole sia valido
    if (numParole <= 0 || numParole > N) {
        printf("Numero non valido. Assicurati di inserire un numero compreso tra 1 e %d.\n", N);
        return 1; // Termina il programma con un codice di errore
    }

    // Pulisce il buffer di input
    while (getchar() != '\n');

    // Loop per l'inserimento delle parole
    for (i = 0; i < numParole; ++i) {
        // Chiede all'utente di inserire una parola
        printf("Inserisci la parola %d: ", i + 1);
        scanf("%s", buffer);
        // Alloca dinamicamente una nuova stringa della dimensione esatta della parola
        
        parole[i] = (char*) malloc((strlen(buffer)+1) * sizeof(char));
        if (parole[i] == NULL) {
            printf("Errore: allocazione di memoria fallita\n");
            return 1; // Termina il programma con un codice di errore
        }
        
        // Copia la parola nel nuovo spazio allocato
        strcpy(parole[i], buffer);
    }

    // Stampa la frase ottenuta
    printf("\nFrase ottenuta: ");
    for (i = 0; i < numParole; ++i) {
        printf("%s ", parole[i]);
    }
    printf("\n");

    // Libera la memoria allocata dinamicamente
    for (i = 0; i < numParole; ++i) {
        free(parole[i]);
    }

    return 0; // Termina il programma con successo
}
