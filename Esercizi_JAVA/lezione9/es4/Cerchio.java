public class Cerchio {
    private Vett centro;
    private double raggio;

    // Costruttore di default
    public Cerchio() {
        this.centro = new Vett();
        this.raggio = 1.0;
    }

    // Costruttore con centro e raggio
    public Cerchio(Vett centro, double raggio) {
        this.centro = new Vett(centro);
        this.raggio = raggio > 0 ? raggio : 1.0; // Verifica che il raggio sia positivo
    }

    // Costruttore copia
    public Cerchio(Cerchio altroCerchio) {
        this.centro = new Vett(altroCerchio.centro);
        this.raggio = altroCerchio.raggio;
    }

    // Getter e Setter
    public Vett getCentro() {
        return centro;
    }

    public void setCentro(Vett centro) {
        this.centro = centro;
    }

    public double getRaggio() {
        return raggio;
    }

    public void setRaggio(double raggio) {
        if (raggio > 0) {
            this.raggio = raggio;
        }
    }

    // Calcolo del perimetro
    public double calcolaPerimetro() {
        return 2 * Math.PI * raggio;
    }
   
    // Rappresentazione testuale del cerchio
    @Override
    public String toString() {
        return "Centro: " + centro + ", Raggio: " + raggio;
    }
}
