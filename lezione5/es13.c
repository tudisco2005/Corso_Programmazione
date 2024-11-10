/*
Potenza di una matrice.
Tempo: 50 min.
Scrivete un programma che legga in ingresso una matrice A e un intero m ⩾ 0. Il
programma calcola la matrice Per calcolare la potenza iterate il prodotto di A con se
stessa m volte. Troverete utile impiegare una matrice ausiliaria per memorizzare il risultato
parziale AkA, per
k ∈ {0, . . . , m − 1}.
A
m := A × A × · · · × A | {z }
m volte
,
visualizza sia A che Am, e termina.
Nell’Esercizio 13 è ammesso l’esponente m = 0. Come si comporta in questo
caso il vostro programma? Si rammenti che si ha
A
0 = In
per una qualunque matrice n × n di numeri reali, con n un intero n ⩾ 1, dove
In := (δij )
n
i,j=1 è la matrice identità n × n:
δij :=
(
1 if i = j,
0 if i ̸= j.
Assicuratevi che il vostro programma produca l’output corretto a fronte dell’input m = 0. Se la procedura iterativa di calcolo della potenza Am è implementata in modo appropriato, non è necessario eseguire una selezione per
trattare m = 0 come caso particolare.

*/

#include <math.h>
#include <stdio.h>

#define N 3

void enterMatrix(int a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("Enter [%d][%d]: ", y, x);
            scanf("%d", &a[y][x]);
        }
    }
}

void printMatrix(int a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("[%d] ", a[y][x]);
        }
        printf("\n");
    }
}


void multiplymatrices(long int a[][N], int b[][N], long int res[][N]) {
    long int tmp = 0;
    for (int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            tmp = 0;
            for(int k=0;k<N;k++) {
                tmp += a[y][k]*b[k][x];
            }
            res[y][x] = tmp;
        }
    }
}

void copyMatrix(long int src[][N], long int dst[][N]){
    for (int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            dst[y][x] = src[y][x];
        }
    }
}

void matrixPow(int a[][N], int exp, long int res[][N]) {
     for (int y = 0; y < N; y++) {
        for(int x = 0; x < N; x++) {
            res[y][x] = a[y][x];
        }
    }

    // matrice identità
    if (exp == 0) {
        for(int y=0; y<N; y++){
            res[y][y] = 1;
        } 
    } else {
        long int res_tmp[N][N];
        // prodotto tra matrici
        for(exp; exp>1; exp--){
            copyMatrix(res, res_tmp);
            multiplymatrices(res_tmp, a, res);
        }
    }

}

int main() {
    int a[N][N], exp;
    long int res[N][N];

    printf("Enter the matrix:\n");
    enterMatrix(a);

    printf("\n");
    do {
        printf("Enter the exponent:\n");
        scanf("%d", &exp);
    } while(exp < 0);

    printf("\nStarting Matrix:\n");
    printMatrix(a);

    matrixPow(a, exp, res);

    printf("\nEnd Matrix:\n");
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("[%ld] ", res[y][x]);
        }
        printf("\n");
    }
    return 0;
}