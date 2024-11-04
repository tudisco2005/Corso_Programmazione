/*
Esercizio 9
Moltiplicazione per uno scalare.
Tempo: 10 min.
Scrivete un programma che legga una matrice A di dimensione n × n inserita dal-
l’utente, legga poi un numero reale λ ∈ R (tipo double come per gli elementi della
matrice), calcoli la moltiplicazione λA, visualizzi il risultato e termini.
*/

#include <stdio.h>

#define N 2

void enterMatrix(int a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("Enter [%d][%d]: ", y, x);
            scanf("%d", &a[x][y]);
        }
    }
}

void printMatrix(double a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("[%lf] ", a[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int a[N][N];
    double num;

    printf("Enter the matrix A:\n");
    enterMatrix(a);

    printf("\nEnter a real number: ");
    scanf("%lf", &num);
    
    printf("\n----Res----\n");
    double res[N][N];

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("%d * %lf = [%d]\t", a[x][y], num, a[x][y] * num);
            res[x][y] = a[x][y] * num;
        }
        printf("\n");
    }

    printf("\n");
    printMatrix(res);
}