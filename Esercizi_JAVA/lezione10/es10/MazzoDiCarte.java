import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MazzoDiCarte {
    private static final int NUM_CARTE = 52; // Costante per il numero di carte
    private final List<Carta> carte;        // Lista di carte nel mazzo
    private int indiceDistribuzione;        // Indice della prossima carta da distribuire
    private static final SecureRandom random = new SecureRandom(); // Generatore casuale

    // Costruttore
    public MazzoDiCarte() {
        this.carte = new ArrayList<>(NUM_CARTE);
        this.indiceDistribuzione = 0;

        // Creazione del mazzo ordinato
        for (Carta.Seme seme : Carta.Seme.values()) {
            for (Carta.Valore valore : Carta.Valore.values()) {
                this.carte.add(new Carta(seme, valore));
            }
        }
    }

    // Metodo per mescolare il mazzo
    public void mescola() {
        Collections.shuffle(this.carte, random);
        this.indiceDistribuzione = 0; // Reimposta l'indice di distribuzione
    }

    // Metodo per distribuire una carta
    public Carta distribuisci() {
        if (indiceDistribuzione >= NUM_CARTE) {
            throw new IllegalStateException("Tutte le carte sono state distribuite.");
        }
        return this.carte.get(indiceDistribuzione++);
    }

    // Metodo per visualizzare il mazzo come stringa
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Carta carta : carte) {
            sb.append(carta).append("\n");
        }
        return sb.toString();
    }

    
}
