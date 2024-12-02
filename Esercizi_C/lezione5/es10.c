/*
Prodotto di matrici.
Tempo: 25 min.
Scrivete un programma che legga due matrici n × n inserite dall’utente, ne calcoli
il prodotto, visualizzi i fattori e il prodotto e termini.
*/


#include <stdio.h>

#define N 3

void enterMatrix(int a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("Enter [%d][%d]: ", y, x);
            scanf("%d", &a[x][y]);
        }
    }
}

void printMatrix(int a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("[%d] ", a[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int a[N][N];
    int b[N][N];

    printf("Enter matrix a:\n");
    enterMatrix(a);

    printf("\nEnter matrix b:\n");
    enterMatrix(b);


    printf("\nMatrix A:\n");
    printMatrix(a);

    printf("\nMatrix B:\n");
    printMatrix(b);

    printf("\n----multiply----\n");
    long int multiply[N][N];
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            multiply[y][x] = 0;
        }
    }

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            for(int k=0;k<N;k++) {
                multiply[y][x] += a[y][k]*b[k][x];
            }
        }
    }

    printf("\n----result----\n");
     for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("[%ld] ", multiply[x][y]);
        }
        printf("\n");
    }
    return 0;
}