/*
Area di un triangolo.
Tempo: 25 min.
Si scriva una funzione di prototipo:
double area(Tri *)
che restituisca l’area del triangolo puntato dall’argomento. Per calcolare l’area del
triangolo potete usare la formula di Erone: detta µ(T) l’area del triangolo T, si ha
µ(T) = p
s(s − a)(s − b)(s − c),
dove a, b e c sono le lunghezze dei tre lati di T, ed s := 1
2
(a + b + c) ne è
il semiperimetro. Scrivete una funzione main che permetta di testare la vostra
implementazione
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

double pointDistance(Vett a, Vett b) {
    return (double) sqrt(pow((a.x - b.x),2) + pow(a.y - b.y,2));
}

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


double area(Tri *tmp) {
    if(!degenere(tmp)) return 0;

    double ab = pointDistance(tmp->a,tmp->b);
    double bc = pointDistance(tmp->b,tmp->c);
    double ca = pointDistance(tmp->c,tmp->a);

    double s = 0.5 * ( ab + bc + ca );

    return (double) sqrt(s*(s-ab)*(s-bc)*(s-ca));
}

int main() {
    Tri t1 = {
        {0, 0},
        {1, 0},
        {0, 1}
    };
    
    // Test case 2: triangolo degenere (punti allineati)
    Tri t2 = {
        {0, 0},
        {1, 1},
        {2, 2}
    };
    
    // Test case 3: triangolo più grande
    Tri t3 = {
        {0, 0},
        {4, 0},
        {0, 3}
    };
    
    printf("Test triangolo 1: ");
    double area1 = area(&t1);
    if (area1 > 0) {
        printf("Area = %.2f\n", area1);
    } else {
        printf("Triangolo degenere\n");
    }
    
    printf("Test triangolo 2: ");
    double area2 = area(&t2);
    if (area2 > 0) {
        printf("Area = %.2f\n", area2);
    } else {
        printf("Triangolo degenere\n");
    }
    
    printf("Test triangolo 3: ");
    double area3 = area(&t3);
    if (area3 > 0) {
        printf("Area = %.2f\n", area3);
    } else {
        printf("Triangolo degenere\n");
    }

    return 0;
}

