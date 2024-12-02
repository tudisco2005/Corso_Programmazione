#include <stdio.h>

#define N 3


void printMatrix(char a[][N]) {
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            printf("[%c] ", a[y][x]);
        }
        printf("\n");
    }
}


int main() {
    char matrix[N][N] = {
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
    };

    printf("Starting:\n");
    printMatrix(matrix);

    // swap along the diagonal (transpose)
    char temp;
    for(int y=0; y<N; y++) {
        for(int x=y+1; x<N; x++) {
            printf("Swapping %c <-> %c\n", matrix[y][x], matrix[x][y]);
            temp = matrix[y][x];
            matrix[y][x] = matrix[x][y];
            matrix[x][y] = temp;
        }
    }

    printf("\nEnd:\n");
    printMatrix(matrix);

    return 0;
}

