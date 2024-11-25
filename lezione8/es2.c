/*
Parte 2
Classe main e esercizi semplici.
Tempo: 60 min.
La seconda parte dell’esame vi chiede di implementare delle funzioni semplici
su alcuni argomenti trattati durante il corso. Leggete bene il tema di esame
perché spesso alcune funzioni sono utili anche a voi per debuggare il vostro
codice; partite da sviluppare quelle funzioni, e poi potrete riutilizzarle. Ad
esempio, in questo caso, la funzione stampa vi è molto utile.

Esercizio 2.1 Implementa una funzione salva(), che riceve come input una lista,
definita come in Esercizio 1, e un nome di file. La funzione scrive i valori della lista
nel file, uno per volta.

Esercizio 2.2 Implementa una funzione carica(), che riceve come input un nome
di file e legge da esso un numero, non noto a priori, di interi. Tali valori verranno
inseriti in testa in una lista definita come nell’Esercizio 1. In caso il file esista,
assumete che sia strutturato in maniera corretta.

Esercizio 2.3 Implementa una funzione stampa() che stampa a schermo il conte-
nuto della lista, in ordine.

Esercizio 2.4 Scrivete una funzione rimuovi() che elimina un elemento dalla
lista, dato il suo valore. In caso l’elemento non sia presente nella lista, la funzione
ritornerà −1. Nel caso vi siano più occorrenze dell’elemento nella lista, solo una
verrà eliminata. Nel caso l’elemento sia presente, la funzione restituisce il valore
dell’elemento eliminato.
Gestire le eccezioni.

Esercizio 2.5 Implementa una funzione ricorsiva stampaRicorsiva che stampi
a schermo gli elementi della lista in ordine inverso. Utilizzate la ricorsione per
ottenere questo risultato. Ad esempio, se la lista contiene 19, 12, 37, 22 a schermo
dovrà essere stampato 22, 37, 12, 19.

Esercizio 2.6
Il main è una collezione delle funzioni che avete sviluppato. Potete farlo mano
a mano che sviluppate le singole funzioni.

Scrivere un main() che permetta all’utente di utilizzare una lista. Il main() chiederà
un valore numerico all’utente e si comporterà nel seguente modo:
1 Aggiungi un elemento in testa (inserito dall’utente)
2 Rimuovi un elemento dalla testa
3 Aggiungi un elemento in coda (inserito dall’utente)
4 Rimuovi un elemento dalla coda
5 Rimuovi un elemento in lista (inserito dall’utente)
6 Carica lista da file
7 Salva lista su file
8 Stampa
9 Stampa la lista in ordine inverso
10 Cancella gli elementi di una lista.
0 Esci dal programma
Il programma continuerà a chiedere una nuova istruzione valida all’utente in ma-
niera continuata, fino all’inserimento del valore di uscita.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;    
} Node;

void stampa(Node *head) {
    Node *curr = head;
    while(curr) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int inserisciInTesta(Node **head, const int data_to_enter) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Errore durante l'allocazione");
        return -1;
    }
    new_node->data = data_to_enter;
    new_node->next = *head;

    *head = new_node;
    return (*head)->data;
}

int inserisciInCoda(Node **head, const int data_to_enter) {
    Node *curr = *head;
    while(curr->next) {
        curr = curr->next;
    }

    Node *new_node = (Node*) malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Errore durante l'allocazione");
        return -1;
    }
    new_node->data = data_to_enter;
    new_node->next = NULL;
    curr->next = new_node;
    return curr->next->data;
}

int rimuoviInTesta(Node **head) {
    if((*head) == NULL) {
        printf("The head of the list is NULL\n");
        return -1;
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return 0;
    }

    Node *prev_head = (*head);
    *head = (*head)->next;
    free(prev_head);
    return 0;
}

int rimuoviInCoda(Node **head) {
    if((*head) == NULL) {
        printf("The head of the list is NULL\n");
        return -1;
    }
    if((*head)->next == NULL) {
        free((*head));
        (*head) = NULL;
        return 0;
    }

    Node *end = *head;
    while(end->next->next) {
        end = end->next;
    }
    free(end->next);
    end->next = NULL;
    return 0;
}

int cancella(Node **head) {
    if((*head) == NULL) {
        printf("The head of the list is NULL\n");
        return -1;
    }
    while((*head) != NULL) {
        rimuoviInTesta(head);
    }
    return 0;
}

int inizializzaLista(Node **head, const int data_to_enter) {
    if((*head) != NULL) {
        printf("The head is pointing to something, is not NULL\n");
        return 0;
    } 
    (*head) = (Node*) malloc(sizeof(Node));
    (*head)->data = data_to_enter;
    (*head)->next = NULL;
    return 0;
}

int salva(Node *head, char filename[]) {
    FILE *fptr = fopen(filename, "w");
    if(fptr == NULL) {
        printf("Error opening the file\n");
        return -1;
    }
    while (head){
        fprintf(fptr, "%d,\n",head->data);
        head = head->next;
    }
    
    if(fclose(fptr) != 0) {
        printf("Error closing the file\n");
        return -1;
    }
    return 0;
}

int carica(Node **head, char filename[], const int items_to_load) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening the file\n");
        return -1;
    }

    int tmp;
    int read_count = fscanf(fptr, "%d,\n", &tmp);
    if (read_count == EOF) { // Il file è vuoto
        printf("The file is empty\n");
        fclose(fptr); // Chiudi il file prima di uscire
        return -1;
    }

    while (read_count != EOF) {
        inserisciInTesta(head, tmp);
        read_count = fscanf(fptr, "%d,\n", &tmp);
    }

    if (fclose(fptr) != 0) {
        printf("Error closing the file\n");
        return -1;
    }

    return 0;
}

int rimuovi(Node **head, const int value_to_remove) {
    if((*head) == NULL) {
        printf("The head of the list is NULL\n");
        return -2;
    }

    int revoved_value = 0;
    Node *curr = *head;
    if(curr->data == value_to_remove) {
        revoved_value = curr->data;
        rimuoviInTesta(head);
        return revoved_value;
    }

    while (curr->next) {
        if(curr->next->data == value_to_remove) {
            revoved_value = curr->next->data;
            curr->next = curr->next->next;
            return revoved_value;
        }
        curr = curr->next;
    }
    return -1;
}

void stampaRicorsiva(Node *curr) {
    // Base case
    if (curr == NULL)
        return;

    // print the list after head node
    stampaRicorsiva(curr->next);

    // After everything else is printed, print head
    printf("%d -> ", curr->data);
}

int main() {
    Node *head = NULL;
    inizializzaLista(&head, 0);

    stampa(head);
    printf("Entered: %d\n", inserisciInCoda(&head, 10));
    stampa(head);
    printf("Entered: %d\n", inserisciInTesta(&head, 99));
    stampa(head);
    rimuoviInTesta(&head);
    rimuoviInTesta(&head);
    rimuoviInTesta(&head);
    rimuoviInTesta(&head);

    stampa(head);
    inserisciInTesta(&head, 99);
    stampa(head);
    rimuoviInCoda(&head);
    stampa(head);
    inserisciInTesta(&head, -99);
    inserisciInCoda(&head, -98);
    stampa(head);
    rimuoviInCoda(&head);
    stampa(head);

    for(int i=1; i<10; i++) {
        inserisciInCoda(&head, i);
        inserisciInTesta(&head, i);
    }
    stampa(head);

    printf("saved\n");
    salva(head, "data.txt");
    stampa(head);
    cancella(&head);
    stampa(head);
    printf("load\n");
    carica(&head, "data.txt", 10);
    stampa(head);
    inserisciInTesta(&head, 121);
    inserisciInCoda(&head, -121);

    // printf("remove: %d\n", -99);
    // rimuovi(&head, -99);
    // stampa(head);

    // printf("remove: %d\n", 121);
    // rimuovi(&head, 121);
    // stampa(head);

    // printf("remove: %d\n", -121);
    // rimuovi(&head, -121);
    stampa(head);

    printf("reverse print:\n");
    stampaRicorsiva(head);
    return 0;
}