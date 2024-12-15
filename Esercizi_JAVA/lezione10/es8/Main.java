/*
Definite una classe Password che rispetti le seguenti caratteristiche:
• Una password valida deve avere almeno 8 caratteri.
• Una password valida deve avere solo lettere e numeri (non caratteri speciali)
• Una password valida deve avere almeno 2 numeri.
Quali attributi deve avere la classe password? Con che visibilità? E quali metodi
deve esporre?
Ad esempio, deve permettere di verifiare che la password inserita dall’utente sia
uguale a quella contenuta dall’oggetto Password. Implementatate il metodo per
farlo.
Nota: per svolgere l’esercizio implementate delle funzioni statiche che verifichino
le caratteristiche di un carattere (se un carattere è un numero, o se è una lettera
maiuscola o minuscola).

Testate la classe con un apposito Main.
Come si potrebbe modificare la classe nel caso le specifiche cambiassero (ad
esempio, se fosse richiesta la presenza di almeno un carattere maiuscolo?). E se
dovessi definire più tipi di Password con caratteristiche diverse, come posso fare?
Implementare le varianti alla classe Password seguendo questa specifica.
 */

public class Main {
    public static void main(String[] args) {
        // Test della validità delle password
        System.out.println(Password.isValid("abc123")); // false
        System.out.println(Password.isValid("abc12345")); // true
        System.out.println(Password.isValid("abc@1234")); // false

        // Test dei costruttori
        Password p1 = new Password("password123");
        System.out.println(p1); // password123

        Password p2 = new Password(12);
        System.out.println(p2); // Password casuale di 12 caratteri

        Password p3 = new Password();
        System.out.println(p3); // Password casuale di 16 caratteri

        // Test del confronto
        System.out.println(p1.compare("password123")); // true
        System.out.println(p1.compare("wrongpassword")); // false
    }
}