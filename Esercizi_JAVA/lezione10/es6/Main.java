/*
Estendere l’oggetto UniqueListArray permettendo che venga creato anche a
partire da un Array di char contentente dei doppioni. Cosa succederebbe se venisse
creato ricevendo invece una String? Implementate anche questa variante.
*/

public class Main {
    public static void main(String[] args) {
        // Test con array di char
        System.out.println("Test con array di char:");
        char[] inputArray = {'a', 'b', 'a', 'c', 'd', 'b', 'e'};
        UniqueListArray uniqueList1 = new UniqueListArray(inputArray);
        System.out.println("Array unico da array di char: " + uniqueList1); // [a, b, c, d, e]

        // Test con stringa
        System.out.println("\nTest con stringa:");
        String inputString = "abacdbe";
        UniqueListArray uniqueList2 = new UniqueListArray(inputString);
        System.out.println("Array unico da stringa: " + uniqueList2); // [a, b, c, d, e]

        // Test con aggiunta manuale
        System.out.println("\nTest con aggiunta manuale:");
        UniqueListArray uniqueList3 = new UniqueListArray(6);
        uniqueList3.add('a'); // true
        uniqueList3.add('b'); // true
        uniqueList3.add('a'); // false (duplicato)
        uniqueList3.add('c'); // true
        uniqueList3.add('d'); // true
        uniqueList3.add('e'); // true
        uniqueList3.add('f'); // false (array pieno)
        System.out.println("Array unico con aggiunta manuale: " + uniqueList3); // [a, b, c, d, e]
    }
}
