/*
Scrivere un programma che permetta di calcolare il perimetro di un cerchio dato il
raggio. Per farlo, creare una classe di tipo Cerchio.
Per definire il centro della classe Cerchio, utilizzate un Vett, definito al punto
precedente. Aggiungete metodi a Vett se ne avete bisogno.
Aggiungere ulteriori classi che possono servire a definire un oggetto di tipo Cerchio.
Utilizzare le classi definite negli esercizi precedenti. Progettate con criteri i costruttori di Cerchio, i metodi, e gli attributi, 
considerando la loro visibilità.

Implementate nuovi metodi per la classe Cerchio:
• Calcolo l’area del cerchio
• Metodo isConcentric per misurare se un cerchio è concentrico rispetto ad
un altro
• Metodo contains che ci dice se uno è contenuto in un altro.
*/

public class Main {
    public static void main(String[] args) {
        Vett centro1 = new Vett(0, 0);
        Vett centro2 = new Vett(3, 4);
        Cerchio c1 = new Cerchio(centro1, 5);
        Cerchio c2 = new Cerchio(centro2, 2);
        Cerchio c3 = new Cerchio(centro1, 3);

        System.out.println("Cerchio c1: " + c1);
        System.out.println("Cerchio c2: " + c2);
        System.out.println("Perimetro di c1: " + c1.calcolaPerimetro());
        System.out.println("Area di c1: " + c1.calcolaArea());
        System.out.println("c1 è concentrico con c2? " + c1.isConcentric(c2));
        System.out.println("c1 contiene c3? " + c1.contains(c3));
    }
}
