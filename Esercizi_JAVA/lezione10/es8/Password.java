import java.util.Random;

public class Password {
    // Attributo privato per contenere la password
    private String value;

    // Costruttore con valore specifico
    public Password(String value) {
        if (!isValid(value)) {
            throw new IllegalArgumentException("La password non è valida.");
        }
        this.value = value;
    }

    // Costruttore con lunghezza specifica
    public Password(int length) {
        this.value = generate(length);
    }

    // Costruttore predefinito (password di 16 caratteri)
    public Password() {
        this.value = generate(16);
    }

    // Metodo statico per verificare se una password è valida
    public static boolean isValid(String value) {
        if (value.length() < 8) {
            return false;
        }

        int digitCount = 0;
        for (char c : value.toCharArray()) {
            if (!isLetterOrDigit(c)) {
                return false; // Contiene caratteri non validi
            }
            if (isDigit(c)) {
                digitCount++;
            }
        }

        return digitCount >= 2; // Deve contenere almeno 2 numeri
    }

    // Metodo per confrontare la password attuale con un'altra
    public boolean compare(String value) {
        return this.value.equals(value);
    }

    // Metodo statico per generare una password casuale di una lunghezza specifica
    public static String generate(int length) {
        if (length < 8) {
            throw new IllegalArgumentException("La lunghezza deve essere almeno 8.");
        }

        Random random = new Random();
        StringBuilder password = new StringBuilder();
        int digitCount = 0;

        while (password.length() < length) {
            char c = (char) (random.nextInt(36) + '0'); // Genera da '0' a 'z'
            if (isLetterOrDigit(c)) {
                password.append(c);
                if (isDigit(c)) {
                    digitCount++;
                }
            }
        }

        // Aggiungi numeri se mancano
        while (digitCount < 2) {
            char c = (char) (random.nextInt(10) + '0'); // Genera solo numeri
            password.setCharAt(random.nextInt(password.length()), c);
            digitCount++;
        }

        return password.toString();
    }

    // Metodo statico per verificare se un carattere è una lettera o un numero
    public static boolean isLetterOrDigit(char c) {
        return isLetter(c) || isDigit(c);
    }

    // Metodo statico per verificare se un carattere è una lettera
    public static boolean isLetter(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }

    // Metodo statico per verificare se un carattere è un numero
    public static boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    @Override
    public String toString() {
        return value;
    }
}
