/*
Tempo: 15 min.
Si scriva una funzione di nome affind che accetti in ingresso tre puntatori a Vett e
restituisca in uscita l’intero 1 se i tre vettori puntati dai parametri in ingresso sono
affinemente indipendenti, e 0 altrimenti. Si scriva poi una funzione main che accetti Si ricordi che, per definizione, i tre vettori
v0, v1, v2 ∈ R2
sono
affinemente indipendenti se i due vettori
v1 − v0, v2 − v0 ∈ R2
sono linearmente indipendenti.
dalla riga di comando le coordinate di tre vettori nel piano, e produca in uscita
sulla console uno dei due messaggi Affinemente indipendenti o Affinemente
dipendenti, a seconda di quale caso si verifichi. Si gestiscano gli errori legati alla
lettura degli argomenti dalla riga di comando.
*/

#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura Vett
typedef struct Vett {
    double x;
    double y;
} Vett;

// Funzione per sottrarre due vettori
Vett sott(Vett a, Vett b) {
    Vett result = {a.x - b.x, a.y - b.y};
    return result;
}

// Funzione per verificare l'indipendenza lineare
int linind(Vett *a, Vett *b) {
    // Calcolo del determinante della matrice formata dai vettori
    double det = a->x * b->y - a->y * b->x;

    // Se il determinante è zero, i vettori sono linearmente dipendenti
    return det != 0;
}

// Funzione per verificare l'indipendenza affine
int affind(Vett *v0, Vett *v1, Vett *v2) {
    // Calcolo dei vettori v1 - v0 e v2 - v0
    Vett v1_minus_v0 = sott(*v1, *v0);
    Vett v2_minus_v0 = sott(*v2, *v0);

    // Verifica dell'indipendenza lineare tra v1 - v0 e v2 - v0
    return linind(&v1_minus_v0, &v2_minus_v0);
}

int main(int argc, char *argv[]) {
    // Controllo del numero di argomenti
    if (argc != 7) {
        printf("Errore: fornire 6 numeri (x0 y0 x1 y1 x2 y2) come argomenti.\n");
        return 1;
    }

    // Conversione degli argomenti in double
    double x0 = atof(argv[1]);
    double y0 = atof(argv[2]);
    double x1 = atof(argv[3]);
    double y1 = atof(argv[4]);
    double x2 = atof(argv[5]);
    double y2 = atof(argv[6]);

    // Creazione dei vettori
    Vett v0 = {x0, y0};
    Vett v1 = {x1, y1};
    Vett v2 = {x2, y2};

    // Verifica dell'indipendenza affine
    if (affind(&v0, &v1, &v2)) {
        printf("Affinemente indipendenti\n");
    } else {
        printf("Affinemente dipendenti\n");
    }

    return 0;
}
