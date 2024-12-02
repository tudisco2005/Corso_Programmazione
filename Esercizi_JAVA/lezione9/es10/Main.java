/*
Estendere la classe Frazione. Fornire i seguenti metodi (e testarli in un appostio
main):

• Fornire un metodo toString che la trasforma in stringa per stamparla
• Fornire metodi predicativi che testano maggiore e minore
• Fornite un metodo equals per dire se una stringa passata in ingresso è equivalente
• Calcolare la frazione inversa
• Fornite la funzione semplifica. Ad esempio, 4/8 va semplificato in 1/2.

Per farlo implementate una funzione esterna che calcola il MCD.
*/

public static void main(String[] args) {
    Frazione f1 = new Frazione(1, 2);
    Frazione f2 = new Frazione(3, 4);

    System.out.println("Frazione 1: " + f1);
    System.out.println("Frazione 2: " + f2);

    System.out.println("Somma: " + f1.somma(f2));
    System.out.println("F1 maggiore di F2: " + f1.isMaggioreDi(f2));
    System.out.println("F1 minore di F2: " + f1.isMinoreDi(f2));
    System.out.println("F1 uguale a '1/2': " + f1.equals("1/2"));
    System.out.println("Frazione inversa di F1: " + f1.inversa());
}