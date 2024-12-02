/*
Indipendenza lineare.
Tempo: 15 min.
Si scriva una funzione di nome linind che accetti in ingresso due puntatori a Vett e
restituisca in uscita l’intero 1 se i due vettori puntati dai parametri in ingresso sono
linearmente indipendenti, e 0 altrimenti. Si scriva poi una funzione main che accetti
dalla riga di comando le coordinate di due vettori nel piano, e produca in uscita
sulla console uno dei due messaggi Linearmente indipendenti o Linearmente
dipendenti, a seconda di quale caso si verifichi. Si gestiscano gli errori legati alla
lettura degli argomenti dalla riga di comando. Per convertire una stringa sulla
riga di comando in double si usi la funzione double atof(char *s) della libreria
standard dichiarata nel file di intestazione stdlib.h.
*/

#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura Vett
typedef struct Vett {
    double x;
    double y;
} Vett;

// Funzione per verificare l'indipendenza lineare
int linind(Vett *a, Vett *b) {
    // Calcolo del determinante della matrice formata dai vettori
    double det = a->x * b->y - a->y * b->x;

    // Se il determinante è zero, i vettori sono linearmente dipendenti
    return det != 0;
}

int main(int argc, char *argv[]) {
    // Controllo del numero di argomenti
    if (argc != 5) {
        printf("Errore: fornire 4 numeri (x1 y1 x2 y2) come argomenti.\n");
        return 1;
    }

    // Conversione degli argomenti in double
    double x1 = atof(argv[1]);
    double y1 = atof(argv[2]);
    double x2 = atof(argv[3]);
    double y2 = atof(argv[4]);

    // Creazione dei vettori
    Vett a = {x1, y1};
    Vett b = {x2, y2};

    // Verifica dell'indipendenza lineare
    if (linind(&a, &b)) {
        printf("Linearmente indipendenti\n");
    } else {
        printf("Linearmente dipendenti\n");
    }

    return 0;
}
