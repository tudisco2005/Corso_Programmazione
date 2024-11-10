/*
Calcolatrice matriciale.
Tempo: 45 min.
Si tratta di mettere Scrivete un programma che acquisisca dall’utente un numero intero n ⩾ 1, e presenti
assieme in un unico
programma il codice che avete scritto
per risolvere gli Esercizi 7–10. Sarebbe
sensato spezzare il
programma in funzioni: poiché però non
abbiamo ancora discusso alcuni aspetti
tecnici del passaggio
di matrici multidimensionali come parametri alle funzioni,
non potrete adottare
questa soluzione, a
meno che non vogliate consultare fin d’ora
le parti rilevanti del
libro di testo.
poi all’utente il menu seguente, dove A e B denotano matrici di numeri reali, ciascuna
di dimensione n × n, ed r denota un numero reale.
1. Inserisci operando A.
2. Inserisci operando B.
3. Inserisci operando scalare r.
4. Visualizza A, B ed r.
5. Trasposta di A.
6. rA.
7. A+B.
8. AB.
9. Scambia A e B.
10. Esci.
Il programma attende la scelta dell’utente ed esegue l’operazione richiesta. Nel caso
in cui vi siano dei dati da visualizzare (scelte 4, 5, 6, 7, 8) il programma li visualizza.
LAB. PROG. — LEZIONE 5 9
Il programma torna poi al al menu. Il programma termina quando l’utente sceglie
10. Nel caso in cui l’utente richieda operazioni che non si possono portare a termine
perché alcuni degli operandi necessari non sono stati ancora inseriti, il programma
informa l’utente della circostanza e torna al menu. Ciò vale anche per la voce 4:
saranno visualizzati solo quei dati fra A, B e r che sono già stati inseriti dall’utente.
*/
#include <stdio.h>

#define DIM 50  // Dimensione massima della matrice

// Flag per tenere traccia degli input
typedef struct {
    int matrice_a;
    int matrice_b;
    int scalare;
} InputFlags;

// Prototipi delle funzioni
void enterMatrix(double matrix[][DIM], int n);
void printMatrix(const double matrix[][DIM], int n);
void multiplyMatrices(const double a[][DIM], const double b[][DIM], int n);
void multiplyScalar(const double matrix[][DIM], double r, int n);
void sumMatrices(const double a[][DIM], const double b[][DIM], int n);
void transpose(double matrix[][DIM], int n);
void swapMatrices(double a[][DIM], double b[][DIM], int n);
int menu(const InputFlags *flags);

int main() {
    double matrice_a[DIM][DIM], matrice_b[DIM][DIM];
    double scalare;
    int n;
    InputFlags flags = {0, 0, 0};  // Inizializza tutti i flag a 0

    // Acquisizione dimensione
    do {
        printf("Inserire la dimensione delle matrici (1 <= n <= 50): ");
        scanf("%d", &n);
    } while(n < 1 || n > DIM);

    int scelta;
    do {
        scelta = menu(&flags);
        
        switch(scelta) {
            case 1:  // Inserisci A
                enterMatrix(matrice_a, n);
                flags.matrice_a = 1;
                break;

            case 2:  // Inserisci B
                enterMatrix(matrice_b, n);
                flags.matrice_b = 1;
                break;

            case 3:  // Inserisci r
                printf("Inserire lo scalare r: ");
                scanf("%lf", &scalare);
                flags.scalare = 1;
                break;

            case 4:  // Visualizza tutto
                if (flags.matrice_a) {
                    printf("\nMatrice A:\n");
                    printMatrix(matrice_a, n);
                }
                if (flags.matrice_b) {
                    printf("\nMatrice B:\n");
                    printMatrix(matrice_b, n);
                }
                if (flags.scalare) {
                    printf("\nScalare r: %lf\n", scalare);
                }
                if (!flags.matrice_a && !flags.matrice_b && !flags.scalare) {
                    printf("Nessun dato inserito.\n");
                }
                break;

            case 5:  // Trasposta di A
                if (!flags.matrice_a) {
                    printf("Inserire prima la matrice A.\n");
                    break;
                }
                transpose(matrice_a, n);
                printf("Trasposta di A:\n");
                printMatrix(matrice_a, n);
                break;

            case 6:  // rA
                if (!flags.matrice_a || !flags.scalare) {
                    printf("Inserire prima la matrice A e lo scalare r.\n");
                    break;
                }
                printf("Prodotto rA:\n");
                multiplyScalar(matrice_a, scalare, n);
                break;

            case 7:  // A+B
                if (!flags.matrice_a || !flags.matrice_b) {
                    printf("Inserire prima entrambe le matrici.\n");
                    break;
                }
                printf("Somma A+B:\n");
                sumMatrices(matrice_a, matrice_b, n);
                break;

            case 8:  // AB
                if (!flags.matrice_a || !flags.matrice_b) {
                    printf("Inserire prima entrambe le matrici.\n");
                    break;
                }
                printf("Prodotto AB:\n");
                multiplyMatrices(matrice_a, matrice_b, n);
                break;

            case 9:  // Scambia A e B
                if (!flags.matrice_a || !flags.matrice_b) {
                    printf("Inserire prima entrambe le matrici.\n");
                    break;
                }
                swapMatrices(matrice_a, matrice_b, n);
                printf("Matrici scambiate.\n");
                break;
        }
    } while(scelta != 10);

    return 0;
}

void enterMatrix(double matrix[][DIM], int n) {
    printf("Inserire gli elementi della matrice:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printMatrix(const double matrix[][DIM], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(const double a[][DIM], const double b[][DIM], int n) {
    double result;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result = 0;
            for(int k = 0; k < n; k++) {
                result += a[i][k] * b[k][j];
            }
            printf("%.2f\t", result);
        }
        printf("\n");
    }
}

void multiplyScalar(const double matrix[][DIM], double r, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", matrix[i][j] * r);
        }
        printf("\n");
    }
}

void sumMatrices(const double a[][DIM], const double b[][DIM], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", a[i][j] + b[i][j]);
        }
        printf("\n");
    }
}

void transpose(double matrix[][DIM], int n) {
    double temp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

void swapMatrices(double a[][DIM], double b[][DIM], int n) {
    double temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp = a[i][j];
            a[i][j] = b[i][j];
            b[i][j] = temp;
        }
    }
}

int menu(const InputFlags *flags) {
    int scelta;
    printf("\nMenu:\n");
    printf("1. Inserisci operando A\n");
    printf("2. Inserisci operando B\n");
    printf("3. Inserisci operando scalare r\n");
    printf("4. Visualizza A, B ed r\n");
    printf("5. Trasposta di A\n");
    printf("6. rA\n");
    printf("7. A+B\n");
    printf("8. AB\n");
    printf("9. Scambia A e B\n");
    printf("10. Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    printf("\n");
    return scelta;
}