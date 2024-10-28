/*
La successione di Fibonacci (versione iterativa).
Tempo: 15 min.
La Figura 4 mostra il sorgente parziale di un programma in C che calcola l’n-esimo
termine della successione di Fibonacci. Manca una sola riga di codice, come indicato
in figura. Aggiungetela, compilate ed eseguite il programma, ed assicuratevi con
qualche esperimento del suo corretto funzionamento.
La successione di Fibonacci
Si consideri la successione di numeri naturali induttivamente definita da:
F1 := 1,
F2 := 1, (⋆)
Fn := Fn−1 + Fn−2 per n ⩾ 3.
La successione (⋆) è nota come successione di Fibonacci.a In Tabella 1 sono
tabulati i primi termini della successione di Fibonacci.
aDal nome di Leonardo Pisano Fibonacci (ca. 1170–ca. 1250), così detto perché figlio del
mercante pisano Guglielmo dei Bonacci. Leonardo fu un importante matematico medievale.
Nel 1202 pubblicò il Liber Abaci, che svolse un ruolo fondamentale nella diffusione in
Occidente del sistema di numerazione indiano basato sulle cifre 0–9, comunemente dette
“arabe”. La successione di Fibonacci compare in un esempio del Liber Abaci.
n 1 2 3 4 5 6 7 8 9 10 11 12 13
Fn 1 1 2 3 5 8 13 21 34 55 89 144 233
Tabella 1. I primi termini della successione di Fibonacci
LAB. PROG. — LEZIONE 3 7
a \ b 1 2 3 4 5 6 7 8
1 1
2 1 1
3 1 2 1
4 1 1 2 1
5 1 2 3 2 1
6 1 1 1 2 2 1
7 1 2 2 3 3 2 1
8 1 1 3 1 4 2 2 1
Tabella 2. Il numero di divisioni eseguito dall’algoritmo euclideo
della Figura 3 per a ⩾ b > 0.
Fibonacci.c
1 #include <stdio.h>
2
3 int main(void)
4 {
5 int n; //il programma calcola F(n)
6
7 do
8 {
9 printf()"Inserisci un intero positivo: ");
10 scanf("%d",&n);
11 } while ( (n<=0) ); //sono ammessi solo interi positivi
12
13 printf("F(%d)=",n);
14
15 int i; //contatore del ciclo for
16 int f_i=1,f_prec=1; //valori iniziali F(2)=F(1)=1
17
18 for (i=3;i<=n;i++) //il ciclo comincia da i=3
19 {
20 int aux=f_i; //variabile ausiliaria aux
21 ...; //somma ad f_i il valore di f_prec
22 f_prec=aux; //f_prec = f_i prima dell'iterazione
23 }
24 printf("%d\n",f_i);
25 }
*/

#include <stdio.h>

int main(void) {
    int n; //il programma calcola F(n)

    do {
        printf("Inserisci un intero positivo: ");
        scanf("%d",&n);
    } while ( (n<=0) ); //sono ammessi solo interi positivi

    printf("F(%d)=",n);

    int i; //contatore del ciclo for
    int f_i=1,f_prec=1; //valori iniziali F(2)=F(1)=1

    for (i=3;i<=n;i++) {//il ciclo comincia da i=3
        int aux = f_i; //variabile ausiliaria aux
        f_i += f_prec; //somma ad f_i il valore di f_prec
        f_prec = aux; //f_prec = f_i prima dell'iterazione
    }
    
    printf("%d\n",f_i);
}