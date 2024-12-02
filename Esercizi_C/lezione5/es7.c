/*
Esercizio 7
Matrice trasposta.
Tempo: 15 min.
Scrivete un programma che legga una matrice n × n inserita dall’utente, ne calcoli
la matrice trasposta, visualizzi entrambe le matrici e termini.
*/

#include <stdio.h>

#define N 3

int main() {
    int matrix[N][N];
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("Enter matrix[%d][%d]: ", y, x);
            scanf("%d", &matrix[x][y]);
        }
    }

    for(int y=0; y<N; y++){
        printf("\n");
        for(int x=0; x<N; x++){
            printf("%d, ",matrix[x][y]);
        }
    }

    printf("\n----swap----\n");

    int temp=0;
    for(int y=0; y<N; y++){
        for(int x=y; x<N; x++){
            temp=matrix[y][x];
            matrix[y][x]=matrix[x][y];
            matrix[x][y]=temp;
        }
    }
    
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("%d, ",matrix[x][y]);
        }
        printf("\n");
    }

    return 0;
}