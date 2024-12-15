/*
Definite una classe Dado, che simuli il comportamento di un dado da gioco.
Ogni dado viene inizializzato con un numero di facce, che poi è fisso. Gestite
accuratamente come definire gli attributi della classe Dado. Definire il metodo
lancia che restituisce un valore casuale simulando il lancio del dado. Definire
infine dei metodi statici che permettano di ottenere un valore lanciato da un dado,
senza aver bisogno di istanziare un oggetto di classe Dado.
Per ottenere un numero casuale intero utilizzate la funzione nextInt(int)
della classe SecureRandom, definita in java.security.SecureRandom.
Testare la classe così creata in un programma main che svolge le seguenti operazioni.
Simulare il 200 lanci di un dado da 20 e contare quante volte ogni occorrenza viene
estratta. Per farlo utilizzare un Array. Visualizzare il risultato a schermo.
*/

public class Main {
    public static void main(String[] args) {
        // Simulazione di 200 lanci di un dado a 20 facce
        int numeroFacce = 20;
        int[] conteggio = new int[numeroFacce]; // Array per contare le occorrenze

        // Creazione di un dado con 20 facce
        Dado dado = new Dado(numeroFacce);

        // Lancio del dado 200 volte
        for (int i = 0; i < 200; i++) {
            int risultato = dado.lancia(); // Lancia il dado
            conteggio[risultato - 1]++; // Incrementa il conteggio della faccia
        }

        // Visualizzazione dei risultati
        System.out.println("Risultati dei 200 lanci del dado a 20 facce:");
        for (int i = 0; i < numeroFacce; i++) {
            System.out.printf("Faccia %2d: %d volte%n", i + 1, conteggio[i]);
        }

        // Test del metodo statico
        System.out.println("\nLancio di un dado statico da 6 facce: " + Dado.lanciaDadoStatico(6));
    }
}