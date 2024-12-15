/*
Scrivere un Oggetto UniqueListArray che, a partire da un Array di char, ne
elimini i doppioni. Specificare al momento della creazione dell’oggetto la grandezza
massima Size.
Per aggiungere un nuovo elemento ad un UniqueListArray utilizzate un metodo
Add che aggiunge un nuovo valore per volta, se non duplicato.
*/

public class Main {
    public static void main(String[] args) {
        // Creazione di un oggetto UniqueListArray con una capacità massima di 5 elementi
        UniqueListArray uniqueList = new UniqueListArray(6);

        // Aggiungiamo alcuni elementi
        System.out.println("Aggiungiamo 'a': " + uniqueList.add('a')); // true
        System.out.println("Aggiungiamo 'b': " + uniqueList.add('b')); // true
        System.out.println("Aggiungiamo 'a' (duplicato): " + uniqueList.add('a')); // false
        System.out.println("Aggiungiamo 'c': " + uniqueList.add('c')); // true
        System.out.println("Aggiungiamo 'd': " + uniqueList.add('d')); // true
        System.out.println("Aggiungiamo 'e': " + uniqueList.add('e')); // true
        System.out.println("Aggiungiamo 'f' (array pieno): " + uniqueList.add('f')); // false

        // Stampa dell'array unico
        System.out.println("Array unico: " + uniqueList);
    }
}
