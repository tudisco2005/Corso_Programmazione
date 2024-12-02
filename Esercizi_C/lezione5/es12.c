/*
Verifica empirica di alcune identità.
Tempo: 45 min.
Scrivete un programma che legga in ingresso tre matrici A, B, C e uno scalare
r ∈ R. Per ciascuna delle identità (1–3), il programma calcola membro destro
e membro sinistro, visualizza i due risultati — che dovrebbero essere uguali — e
termina.
*/

#include <stdio.h>
#define DIM 50

// Prototipi delle funzioni
void enterMatrix(double matrix[][DIM], int n, const char* name);
void printMatrix(const double matrix[][DIM], int n, const char* name);
void multiplyMatrices(const double a[][DIM], const double b[][DIM], double result[][DIM], int n);
void multiplyScalar(const double matrix[][DIM], double r, double result[][DIM], int n);
void addMatrices(const double a[][DIM], const double b[][DIM], double result[][DIM], int n);
void copyMatrix(const double source[][DIM], double dest[][DIM], int n);
void verifyEquality(const double a[][DIM], const double b[][DIM], int n, const char* message);

int main() {
    double A[DIM][DIM], B[DIM][DIM], C[DIM][DIM];
    double temp1[DIM][DIM], temp2[DIM][DIM], left[DIM][DIM], right[DIM][DIM];
    double r;
    int n;

    // Input dimensione
    do {
        printf("Inserire la dimensione delle matrici (n ≥ 1): ");
        scanf("%d", &n);
    } while(n < 1 || n > DIM);

    // Input matrici e scalare
    enterMatrix(A, n, "A");
    enterMatrix(B, n, "B");
    enterMatrix(C, n, "C");
    printf("Inserire lo scalare r: ");
    scanf("%lf", &r);

    printf("\nVerifica delle identità:\n");

    // 1) r(A + B) = rA + rB
    printf("\n1) r(A + B) = rA + rB\n");
    
    // Calcolo lato sinistro: r(A + B)
    addMatrices(A, B, temp1, n);
    multiplyScalar(temp1, r, left, n);
    
    // Calcolo lato destro: rA + rB
    multiplyScalar(A, r, temp1, n);
    multiplyScalar(B, r, temp2, n);
    addMatrices(temp1, temp2, right, n);
    
    verifyEquality(left, right, n, "r(A + B) = rA + rB");

    // 2) (AB)C = A(BC)
    printf("\n2) (AB)C = A(BC)\n");
    
    // Calcolo lato sinistro: (AB)C
    multiplyMatrices(A, B, temp1, n);
    multiplyMatrices(temp1, C, left, n);
    
    // Calcolo lato destro: A(BC)
    multiplyMatrices(B, C, temp1, n);
    multiplyMatrices(A, temp1, right, n);
    
    verifyEquality(left, right, n, "(AB)C = A(BC)");

    // 3) r(AB) = (rA)B = A(rB)
    printf("\n3) r(AB) = (rA)B = A(rB)\n");
    
    // Calcolo r(AB)
    multiplyMatrices(A, B, temp1, n);
    multiplyScalar(temp1, r, left, n);
    
    // Calcolo (rA)B
    multiplyScalar(A, r, temp1, n);
    multiplyMatrices(temp1, B, right, n);
    verifyEquality(left, right, n, "r(AB) = (rA)B");
    
    // Calcolo A(rB)
    multiplyScalar(B, r, temp1, n);
    multiplyMatrices(A, temp1, right, n);
    verifyEquality(left, right, n, "r(AB) = A(rB)");

    return 0;
}

void enterMatrix(double matrix[][DIM], int n, const char* name) {
    printf("\nInserire gli elementi della matrice %s:\n", name);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(const double matrix[][DIM], int n, const char* name) {
    printf("\nMatrice %s:\n", name);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(const double a[][DIM], const double b[][DIM], double result[][DIM], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = 0;
            for(int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void multiplyScalar(const double matrix[][DIM], double r, double result[][DIM], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = matrix[i][j] * r;
        }
    }
}

void addMatrices(const double a[][DIM], const double b[][DIM], double result[][DIM], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void copyMatrix(const double source[][DIM], double dest[][DIM], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dest[i][j] = source[i][j];
        }
    }
}

void verifyEquality(const double a[][DIM], const double b[][DIM], int n, const char* message) {
    int equal = 1;
    const double epsilon = 1e-10;  // Tolleranza per il confronto di numeri floating-point
    
    for(int i = 0; i < n && equal; i++) {
        for(int j = 0; j < n && equal; j++) {
            if(fabs(a[i][j] - b[i][j]) > epsilon) {
                equal = 0;
            }
        }
    }
    
    printf("\nVerifica: %s\n", message);
    printf("Lato sinistro:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLato destro:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", b[i][j]);
        }
        printf("\n");
    }
    
    printf("\nRisultato: %s\n", equal ? "Identità verificata" : "Identità NON verificata");
}