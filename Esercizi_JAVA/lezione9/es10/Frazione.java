public class Frazione {
private int numeratore;
    private int denominatore;

    // Costruttore
    public Frazione(int numeratore, int denominatore) {
        if (denominatore == 0) {
            throw new IllegalArgumentException("Il denominatore non può essere zero.");
        }
        if (denominatore < 0) {
            numeratore = -numeratore;
            denominatore = -denominatore;
        }
        int gcd = gcd(Math.abs(numeratore), Math.abs(denominatore));
        this.numeratore = numeratore / gcd;
        this.denominatore = denominatore / gcd;
    }

    // Metodo per calcolare il massimo comun divisore
    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
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

    // Override del metodo toString
    @Override
    public String toString() {
        if (denominatore == 1) {
            return String.valueOf(numeratore);
        }
        return numeratore + "/" + denominatore;
    }

    // Metodo predicativo: maggiore di
    public boolean isMaggioreDi(Frazione altra) {
        return this.numeratore * altra.denominatore > altra.numeratore * this.denominatore;
    }

    // Metodo predicativo: minore di
    public boolean isMinoreDi(Frazione altra) {
        return this.numeratore * altra.denominatore < altra.numeratore * this.denominatore;
    }

    // Metodo equals per confronto con stringa
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof String) {
            try {
                String[] parts = ((String) obj).split("/");
                int num = Integer.parseInt(parts[0].trim());
                int den = Integer.parseInt(parts[1].trim());
                Frazione altra = new Frazione(num, den);
                return this.numeratore == altra.numeratore && this.denominatore == altra.denominatore;
            } catch (Exception e) {
                return false;
            }
        }
        return false;
    }

    // Calcolo della frazione inversa
    public Frazione inversa() {
        if (this.numeratore == 0) {
            throw new ArithmeticException("La frazione inversa non esiste per numeratore zero.");
        }
        return new Frazione(this.denominatore, this.numeratore);
    }
}
