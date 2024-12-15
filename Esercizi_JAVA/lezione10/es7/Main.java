/*
Estendere l’esercizio precedente in maniera tale che, oltre ai caratteri, possa avere
in ingresso oggetti di altro tipo come ad esempio Vett, Frazioni, eccetera. Per
farlo, utilizzare l’oggetto generico Object.
Che tipo di ADT rappresenta questa lista? Quale metodo devono avere que-
sti oggetti al fine di poter eliminare i doppi? Pensate prima alla struttura del
programma e delle classi prima di iniziare l’implementazione.
*/

public class Main {
    public static void main(String[] args) {
        // Test con caratteri
        UniqueListArray charList = new UniqueListArray(10);
        charList.add('a');
        charList.add('b');
        charList.add('a'); // Duplicate
        charList.add(10); // Duplicate
        System.out.println(charList);

        // Test con stringhe
        UniqueListArray stringList = new UniqueListArray(5);
        stringList.add("test");
        stringList.add("example");
        stringList.add("test"); // Duplicate
        System.out.println(stringList);

        // Test con oggetti personalizzati
        UniqueListArray fractionList = new UniqueListArray(5);
        fractionList.add(new Fraction(1, 2));
        fractionList.add(new Fraction(1, 2)); // Duplicate
        fractionList.add(new Fraction(2, 3));
        System.out.println(fractionList);
    }
}