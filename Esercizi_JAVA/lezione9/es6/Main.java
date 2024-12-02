/*
Creare una classe Segmento basandosi su Vett. Per farlo, aggiungete i metodi
necessari a Vett. Create un metodo equals per Vett e per Segmento (che stabilisca
se due oggetti - dello stesso tipo - sono equivalenti) e un metodo copy, che crea
una copia di un oggetto identico all’attuale. Fare lo stesso per la classe Cerchio.
Implementare la classe Linea, definita come la retta che passa tra due punti.
Testare i metodi sviluppati in un apposito main.
*/

public class Main {
    public static void main(String[] args) {
        Vett p1 = new Vett(1, 2);
        Vett p2 = new Vett(4, 6);
        Vett p3 = new Vett(1, 2);

        Segmento s1 = new Segmento(p1, p2);
        Segmento s2 = new Segmento(p1, p3);

        System.out.println("Segmento s1: " + s1);
        System.out.println("Segmento s2: " + s2);
        System.out.println("Lunghezza di s1: " + s1.lunghezza());
        System.out.println("s1 e s2 sono uguali? " + s1.equals(s2));

        Segmento l1 = new Segmento(p1, p2);
        Segmento l2 = new Segmento(p2, p3);
        System.out.println("l1 è parallela a l2? " + l1.isParallela(l2));
    }
}
