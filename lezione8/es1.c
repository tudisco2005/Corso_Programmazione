/*
Parte 1
Funzioni di base per gestire una lista.
Tempo: 60 min.

1 8 2 ⊥

Figura 1. Esempio di una lista contenente tre valori. Le freccie
indicano che un nodo contiene un riferimento ad un altro elemento
della lista, mentre il simbolo ⊥ rappresenta il valore NULL.
Una lista è una struttura dati dinamica composta da un insieme di elementi
detti nodi collegati linearmente tra loro. Ogni nodo non è altro che un contenitore
di dati. Nel nostro caso ogni nodo conterrà un valore numerico intero (int).
Avrete a disposizione il materiale caricato durante le lezioni sui siti del corso.
Potrete consultarlo, e usarlo come riferimento durante l’esame. Inoltre se
ne avete, potete portare dei libri di testo. Questo vuol dire che non siete
sicurissimi su di un argomento, o volete essere sicuri sulla sintassi di qualche
costrutto, potete fare riferimento alla documentazione. Usatela.

All’interno di una lista, ogni nodo contiene un riferimento (un puntatore) al nodo
successivo (next), mentre la lista terrà un riferimento al primo nodo (header). Una
lista vuota è un puntatore a NULL.
In questo esercizio dovrete implementare una lista e le funzioni che gestiscono
come vengono inseriti e rimossi dei dati da essa. Vi chiediamo di implementare una
lista che supporti diverse modalità di inserimento e di rimozione degli elementi. La
lista dovrà permettere all’utente di effettuare le seguenti operazioni:
• inserisciInTesta(): inserisce un nuovo elemento nella lista in prima
posizione, in testa alla lista;
• inserisciInCoda(): inserisce un nuovo elemento nella lista in ultima
posizione, in coda alla lista;
• rimuoviInTesta(): rimuove il primo elemento della lista, la testa;
• rimuoviInCoda(): rimuove l’ultimo elemento della testa, la coda.
Per inserire un nuovo elemento nella lista, dovrete creare un nuovo nodo in maniera
dinamica. Un esempio di una lista contenente 3 valori è visibile in Figura 1. Alla
fine della Parte 2 trovate un esempio di utilizzo della lista

Esercizio 1.1
Definite una struttura Nodo che rappresenta un nodo della lista. La struttura
contiene un campo per il valore dell’elemento, e un campo che si riferisce al nodo
successivo. Il valore contenuto da un nodo è un numero intero.

Esercizio 1.2
Scrivete una funzione inserisciInTesta() che prende in input un valore intero e
lo inserisce in testa alla lista. La funzione restituisce il valore dell’elemento inserito,
−1 in caso di errore.

Esercizio 1.3
Scrivete una funzione inserisciInCoda() che prende in input un valore intero e
lo inserisce in coda alla lista. La funzione restituisce il valore dell’elemento inserito,
−1 in caso di errore.

Esercizio 1.4
Scrivete una funzione rimuoviInTesta() che elimina il primo valore della lista.
Restituisce −1 se la lista è vuota.

Esercizio 1.5
Scrivete una funzione rimuoviInCoda() che elimina l’ultimo elemento della lista.
Restituisce −1 se la lista è vuota.

Esercizio 1.6
Scrivete una funzione cancella() che, ricevuto una lista, ne cancelli ogni suo
elemento, svuotandola.

Attenzione alla gestione della memoria allocata dinamicamente.
Quando trovate una indicazione che dovete prestare attenzione a qualcosa,
significa che dovete farlo. In questo caso, la nota vi suggerisce che dovreste
ricordarvi sempre che una malloc abbia avuto successo, e dovrete fare una
free ogni volta che una porzione di memoria non è più necessaria
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;    
} Node;

void printflist(Node *head) {
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

int main() {
    Node *head = NULL;
    inizializzaLista(&head, 0);

    printflist(head);
    printf("Entered: %d\n", inserisciInCoda(&head, 10));
    printflist(head);
    printf("Entered: %d\n", inserisciInTesta(&head, 99));
    printflist(head);
    rimuoviInTesta(&head);
    rimuoviInTesta(&head);
    rimuoviInTesta(&head);
    rimuoviInTesta(&head);

    printflist(head);
    inserisciInTesta(&head, 99);
    printflist(head);
    rimuoviInCoda(&head);
    printflist(head);
    inserisciInTesta(&head, -99);
    inserisciInCoda(&head, -98);
    printflist(head);
    rimuoviInCoda(&head);
    printflist(head);

    for(int i=1; i<10; i++) {
        inserisciInCoda(&head, i);
        inserisciInTesta(&head, i);
    }
    printflist(head);
    cancella(&head);
    printflist(head);

    return 0;
}