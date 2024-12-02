/*
Triangoli.
Tempo: 10 min.
Definite il tipo Tri, i cui valori rappresentano triangoli nel piano euclideo. Il tipo
è definito come una struttura di tre campi, ciascuno di tipo Vett, che rappresentano le coordinate dei tre vertici del triangolo. Chiamate i tre campi v1, v2 e v3,
rispettivamente.
Si scriva una funzione di prototipo:
int degenere(Tri *)
che restituisca 1 se il triangolo puntato dall’argomento è degenere — ossia, se i suoi
vertici sono affinemente dipendenti — e 0 altrimenti. Scrivete una funzione main
che permetta di testare la vostra implementazione.
*/
#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura Vett
typedef struct Vett {
    double x;
    double y;
} Vett;

typedef struct Tri {
    Vett a;
    Vett b;
    Vett c;
} Tri;

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
int affind(Tri *tri)
{
    Vett v1 = sott(tri->b, tri->a);
    Vett v2 = sott(tri->c, tri->a);
    
    return linind(&v1, &v2);
}

// Funzione per verificare se un triangolo è degenere
int degenere(Tri *tri)
{
    return affind(tri);
}

// Funzione main per testare l'implementazione
int main()
{
    Tri t1 = {{0, 0}, {1, 0}, {0, 1}};
    Tri t2 = {{0, 0}, {0, 0}, {0, 0}};

    printf("Is triangle t1 degenerate? %d\n", degenere(&t1));
    printf("Is triangle t2 degenerate? %d\n", degenere(&t2));

    return 0;
}
