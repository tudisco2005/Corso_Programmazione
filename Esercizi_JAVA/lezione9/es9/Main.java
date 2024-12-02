/*
Definire una classe Frazione. 
Come per gli esercizi precedenti, pensate prima di
iniziare l’implementazione al suo stato, alla sua interfaccia. Riflettete su quali sono
le operazioni possibile su tale oggetto, e che requisiti anno. Definite ed implementate
i suoi costruttori. In particolare, controllate quali sono le condizioni da rifiutare
durante la creazione di un nuovo oggetto Frazione. Usare il main per testare
interfaccia e verificarne i vincoli. 
*/

 public static void main(String[] args) {
    Frazione f1 = new Frazione(1, 2);
    Frazione f2 = new Frazione(3, 4);

    System.out.println("Frazione 1: " + f1);
    System.out.println("Frazione 2: " + f2);

    System.out.println("Somma: " + f1.somma(f2));
    System.out.println("Sottrazione: " + f1.sottrai(f2));
    System.out.println("Moltiplicazione: " + f1.moltiplica(f2));
    System.out.println("Divisione: " + f1.dividi(f2));
    System.out.println("Valore decimale di F1: " + f1.toDecimal());
}