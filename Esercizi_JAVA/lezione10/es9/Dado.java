import java.security.SecureRandom;
import java.util.Arrays;

public class Dado {
    // Attributi della classe
    private final int numeroFacce; // Numero di facce del dado
    private static final SecureRandom random = new SecureRandom(); // Generatore di numeri casuali

    // Costruttore
    public Dado(int numeroFacce) {
        if (numeroFacce < 2) {
            throw new IllegalArgumentException("Un dado deve avere almeno 2 facce.");
        }
        this.numeroFacce = numeroFacce;
    }

    // Metodo per lanciare il dado (metodo di istanza)
    public int lancia() {
        return random.nextInt(numeroFacce) + 1; // Genera un numero da 1 a numeroFacce
    }

    // Metodo statico per lanciare un dado senza istanziare un oggetto
    public static int lanciaDadoStatico(int numeroFacce) {
        if (numeroFacce < 2) {
            throw new IllegalArgumentException("Un dado deve avere almeno 2 facce.");
        }
        return random.nextInt(numeroFacce) + 1;
    }
}