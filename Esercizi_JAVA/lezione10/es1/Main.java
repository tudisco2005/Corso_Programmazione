/*
Implementare la classe Matrice che rappresenta la classe di matrici di numeri
interi.
• Definire attributi e metodi per gestire questa entità
• Tra i metodi, deve permettere di fare la somma, moltiplicazione (moltipli-
cazione matriciale riga per colonna, moltiplicazione per uno scalare.
Scrivete un Main per testare i metodi.
*/

public class Main {
    public static void main(String[] args) {
        Matrice a = new Matrice(new int [][] {
            new int [] {1,2,3},
            new int [] {4,5,6},
            new int [] {7,8,9}
        });

        Matrice b = new Matrice(new int [][] {
            new int [] {10,20,30},
            new int [] {40,50,60},
            new int [] {70,80,90}
        });

        System.out.println("Matrice A");
        System.out.println(a);

        System.out.println("\nMatrice B");
        System.out.println(b);

        System.out.println("\nSomma = ");
        System.out.println(a.somma(b));

        System.out.println("\nMoltiplicazione tra matrici =");
        System.out.println(a.moltiplicazione_tra_matrici(b));

        System.out.println("\nMoltiplicazione con scalare =");
        System.out.println(a.moltiplicazione_con_scalare(4));
    }
}