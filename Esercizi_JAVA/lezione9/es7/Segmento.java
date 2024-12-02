import java.lang.Math;


public class Segmento {
    private Vett punto1;
    private Vett punto2;

    public Segmento(Vett punto1, Vett punto2) {
        this.punto1 = punto1.copy();
        this.punto2 = punto2.copy();
    }

    public Segmento(Segmento altra) {
        this(altra.punto1, altra.punto2);
    }

    public Segmento copy() {
        return new Segmento(this);
    }

    public double lunghezza() {
        return Math.sqrt(Math.pow(punto2.getX() - punto1.getX(),2) + Math.pow(punto2.getY() - punto1.getY(),2));
    }

    public boolean isParallela(Segmento altra) {
        int dx1 = this.punto2.getX() - this.punto1.getX();
        int dy1 = this.punto2.getY() - this.punto1.getY();
        int dx2 = altra.punto2.getX() - altra.punto1.getX();
        int dy2 = altra.punto2.getY() - altra.punto1.getY();
        return dx1 * dy2 == dy1 * dx2;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Segmento altra = (Segmento) obj;
        return (punto1.equals(altra.punto1) && punto2.equals(altra.punto2)) ||
                (punto1.equals(altra.punto2) && punto2.equals(altra.punto1));
    }

    @Override
    public String toString() {
        return "Segmento da " + punto1 + " a " + punto2;
    }
}