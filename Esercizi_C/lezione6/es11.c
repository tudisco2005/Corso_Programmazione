/*
Operazioni sui vettori.
Tempo: 25 min.

Si scrivano funzioni di prototipo:
Vett somma(Vett,Vett)
Vett invadd(Vett)
Vett sott(Vett,Vett)
Vett pscal(Vett)
double pint(Vett,Vett)

che implementino, rispettivamente, le operazioni di somma, inverso additivo (⃗v 7→
−⃗v), sottrazione, prodotto per uno scalare e prodotto interno standard. Scrivete
una funzione main che permetta di testare le vostre implementazioni.
*/

#include <stdio.h>

// Definizione della struttura Vett
typedef struct Vett {
    double x;
    double y;
} Vett;

// Funzione per sommare due vettori
Vett somma(Vett a, Vett b) {
    Vett result = {a.x + b.x, a.y + b.y};
    return result;
}

// Funzione per trovare l'inverso additivo di un vettore
Vett invadd(Vett a) {
    Vett result = {-a.x, -a.y};
    return result;
}

// Funzione per sottrarre due vettori
Vett sott(Vett a, Vett b) {
    Vett result = {a.x - b.x, a.y - b.y};
    return result;
}

// Funzione per moltiplicare un vettore per uno scalare
Vett pscal(Vett a, double scalare) {
    Vett result = {a.x * scalare, a.y * scalare};
    return result;
}

// Funzione per calcolare il prodotto interno (scalare) di due vettori
double pint(Vett a, Vett b) {
    return a.x * b.x + a.y * b.y;
}

int main() {
    // Dichiarazione e inizializzazione di due vettori
    Vett a = {1, 1};
    Vett b = {2, 2};

    // Test delle funzioni
    Vett risultato_somma = somma(a, b);
    printf("Somma: (%lf, %lf)\n", risultato_somma.x, risultato_somma.y);

    Vett risultato_invadd = invadd(a);
    printf("Inverso additivo di A: (%lf, %lf)\n", risultato_invadd.x, risultato_invadd.y);

    Vett risultato_sott = sott(a, b);
    printf("Sottrazione: (%lf, %lf)\n", risultato_sott.x, risultato_sott.y);

    Vett risultato_pscal = pscal(a, 3); // Esempio con scalare = 3
    printf("Prodotto per uno scalare (3): (%lf, %lf)\n", risultato_pscal.x, risultato_pscal.y);

    double risultato_pint = pint(a, b);
    printf("Prodotto interno: %lf\n", risultato_pint);

    return 0;
}
