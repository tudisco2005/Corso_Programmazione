public class Frazione {
    private int numeratore;
    private int denominatore;

    // Costruttore
    public Frazione(int numeratore, int denominatore) {
        if (denominatore == 0) {
            throw new IllegalArgumentException("Il denominatore non può essere zero.");
        }
        // Gestisce segno e riduzione ai minimi termini
        if (denominatore < 0) {
            numeratore = -numeratore;
            denominatore = -denominatore;
        }
       
        this.numeratore = numeratore;
        this.denominatore = denominatore;
    }

    // Metodi getter
    public int getNumeratore() {
        return numeratore;
    }

    public int getDenominatore() {
        return denominatore;
    }

    // Somma
    public Frazione somma(Frazione altra) {
        int nuovoNumeratore = this.numeratore * altra.denominatore + altra.numeratore * this.denominatore;
        int nuovoDenominatore = this.denominatore * altra.denominatore;
        return new Frazione(nuovoNumeratore, nuovoDenominatore);
    }

    // Sottrazione
    public Frazione sottrai(Frazione altra) {
        int nuovoNumeratore = this.numeratore * altra.denominatore - altra.numeratore * this.denominatore;
        int nuovoDenominatore = this.denominatore * altra.denominatore;
        return new Frazione(nuovoNumeratore, nuovoDenominatore);
    }

    // Moltiplicazione
    public Frazione moltiplica(Frazione altra) {
        return new Frazione(this.numeratore * altra.numeratore, this.denominatore * altra.denominatore);
    }

    // Divisione
    public Frazione dividi(Frazione altra) {
        if (altra.numeratore == 0) {
            throw new ArithmeticException("Divisione per zero non consentita.");
        }
        return new Frazione(this.numeratore * altra.denominatore, this.denominatore * altra.numeratore);
    }

    // Conversione in decimale
    public double toDecimal() {
        return (double) numeratore / denominatore;
    }

}