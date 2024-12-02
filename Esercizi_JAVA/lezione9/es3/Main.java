/*
Scrivere una classe che descriva un vettore Vett, che definisce un punto nello
spazio 2D. Pensare a stato ed interfaccia di tale classe:
Prima di scrivere il codice che implementa una classe, pensate al funzionamento che deve avere e alla sua semantica (il suo significato). Una classe può
avere tanti costruttori, pensate a quali possono essere utili (oltre quello di
default).
• stato: caratteristiche intrinseche della classe.
• interfaccia: come interagisce con il resto del mondo
• costruttori: senza parametri, a partire da coordinate intere, a partire da
un altro punto.
Durante la fase di sviluppo, considerare la visibilità di attributi e metodi della
classe. Quali devono essere interni, e quali devono essere richiamabili dall’esterno? Quali sono attributi statici e che devono essere protetti da eventuali
modifiche non desiderate?
Definite ora gli attributi e i metodi che la classe Vett deve avere. Alcuni esempi
sono:
• Possibilità di muovere il punto nello spazio dopo la creazione
• Possibilità di calcolare la distanza dal punto di origine degli assi
• Altre operazioni possono essere necessarie? Definitele e implementatele.
Create un nuovo progetto contenente il main e aggiungete la classe Vett a questo
progetto.
*/

public class Main {
    public static void main(String[] args) {
        Vett v1 = new Vett();
        Vett v2 = new Vett(3, 4);
        Vett v3 = new Vett(v2);

        System.out.println("Vettore v1: " + v1);
        System.out.println("Vettore v2: " + v2);
        System.out.println("Distanza di v2 dall'origine: " + v2.distanzaOrigine());

        v1.muovi(2, 2);
        System.out.println("v1 dopo lo spostamento: " + v1);

        v1.sommaVettore(v2);
        System.out.println("v1 dopo la somma con v2: " + v1);

        System.out.println("v2 è uguale a v3? " + v2.equals(v3));
    }
}
