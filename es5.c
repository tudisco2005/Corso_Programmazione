/*

#include <stdio.h>

 int main() {
 int i,j;
 int n;
 int flag = 0;
 do {
 printf("Inserisci una cifra massima per calcolare i numeri primi: ");
 scanf("%d", &n);
 } while (n<=0);

 printf("Numeri primi fino a %d: 2 ", n);
 for (i = 3; i <= n; i+=2); {
 for (j = 2; j * j <= i; j++)
 if (n % j == 0)
 flag = 0; // Il numero non è primo se è divisibile per i

 if (flag) {
 printf("%d ", i);
 }
 }

 printf("\n");

 return 0;
 }

Trova l’errore.
Tempo: 30 min.
In Figura 1 trovate un programma che dovrebbe calcolare i numeri primi fino ad
n, con n inserito dall’utente. Purtroppo, nello scriverlo, il programmatore è stato
disattento e ha commesso degli errori, almeno 3. Inoltre il codice è scritto male,
e questo rende il compito di trovare l’errore più difficile. Sistemate il programma
in modo tale da renderlo leggibile. Cercate di correggere il programma e farlo
funzionare.
*/

#include <stdio.h>

int main() {
    int i,j;
    int n;
    int flag = 0;
    
    do {
        printf("Inserisci una cifra massima per calcolare i numeri primi: ");
        scanf("%d", &n);
    } while (n<=0);

    printf("Numeri primi fino a %d: 2 ", n);
    for (i = 3; i <= n; i+=2) {
        flag = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0; // Il numero non è primo se è divisibile per j 
            }
        }
        if (flag) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}