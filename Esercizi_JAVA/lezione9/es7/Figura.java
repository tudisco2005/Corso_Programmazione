public class Figura {
    private Cerchio cerchio1;
    private Cerchio cerchio2;
    private Segmento Segmento1;
    private Segmento Segmento2;
    private Segmento Segmento3;

    // Costruttore
    public Figura(Cerchio cerchio1, Cerchio cerchio2, Segmento Segmento1, Segmento Segmento2, Segmento Segmento3) {
        this.cerchio1 = cerchio1.copy();
        this.cerchio2 = cerchio2.copy();
        this.Segmento1 = Segmento1.copy();
        this.Segmento2 = Segmento2.copy();
        this.Segmento3 = Segmento3.copy();
    }

    // Verifica se i due cerchi sono concentrici
    public boolean cerchiConcentrici() {
        return cerchio1.isConcentric(cerchio2);
    }

    // Verifica se le linee si intersecano
    public boolean lineeSiIntersecano() {
        return interseca(Segmento1, Segmento2) || interseca(Segmento1, Segmento3) || interseca(Segmento2, Segmento3);
    }

    // Metodo per verificare l'intersezione tra due linee usando la geometria analitica
    private boolean interseca(Segmento l1, Segmento l2) {
        int x1 = l1.getX(), y1 = l1.getY();
        int x2 = l1.getX(), y2 = l1.getY();
        int x3 = l2.getX(), y3 = l2.getY();
        int x4 = l2.getX(), y4 = l2.getY();

        // Calcolo dei determinanti per verificare l'intersezione
        double detL1 = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (detL1 == 0) return false; // Le linee sono parallele

        return true;
    }

    // Verifica se le tre linee formano un triangolo
    public boolean formanoTriangolo() {
        return !(Segmento1.isParallela(Segmento2) && Segmento1.isParallela(Segmento3));
    }

    @Override
    public String toString() {
        return "Figura composta da:\n" +
                "Cerchio1: " + cerchio1 + "\n" +
                "Cerchio2: " + cerchio2 + "\n" +
                "Segmento1: " + Segmento1 + "\n" +
                "Segmento2: " + Segmento2 + "\n" +
                "Segmento3: " + Segmento3;
    }
}
