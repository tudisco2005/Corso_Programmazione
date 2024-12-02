public class Vett {
    // Attributi privati
    private int x;
    private int y;

    // Costruttore di default
    public Vett() {
        this.x = 0;
        this.y = 0;
    }

    // Costruttore con coordinate specificate
    public Vett(int x, int y) {
        this.x = x;
        this.y = y;
    }

    // Costruttore che copia un altro vettore
    public Vett(Vett altroVett) {
        this.x = altroVett.x;
        this.y = altroVett.y;
    }

    // Getter e setter per le coordinate
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    // Metodo per muovere il punto
    public void muovi(int deltaX, int deltaY) {
        this.x += deltaX;
        this.y += deltaY;
    }

    // Calcola la distanza dall'origine (0, 0)
    public double distanzaOrigine() {
        return Math.sqrt(x * x + y * y);
    }

    // Metodo per sommare un altro vettore
    public void sommaVettore(Vett altroVett) {
        this.x += altroVett.x;
        this.y += altroVett.y;
    }

    public double distanza(Vett altro) {
        return Math.sqrt(Math.pow(this.x - altro.x, 2) + Math.pow(this.y - altro.y, 2));
    }

    // Rappresentazione testuale del vettore
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    
    // Metodo per confrontare due vettori
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Vett altroVett = (Vett) obj;
        return x == altroVett.x && y == altroVett.y;
    }
}
