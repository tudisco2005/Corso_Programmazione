public class Carta {
    // Enum per i semi
    public enum Seme {
        CUORI, QUADRI, FIORI, PICCHE
    }

    // Enum per i valori
    public enum Valore {
        DUE, TRE, QUATTRO, CINQUE, SEI, SETTE, OTTO, NOVE, DIECI, FANTE, DONNA, RE, ASSO
    }

    private final Seme seme;     // Seme della carta
    private final Valore valore; // Valore della carta

    // Costruttore
    public Carta(Seme seme, Valore valore) {
        this.seme = seme;
        this.valore = valore;
    }

    // Metodo toString per rappresentare la carta come "Valore di Seme"
    @Override
    public String toString() {
        return valore + " di " + seme;
    }
}
