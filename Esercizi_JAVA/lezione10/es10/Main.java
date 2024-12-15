/* */

public class Main {
    // Metodo principale per testare la classe
    public static void main(String[] args) {
        MazzoDiCarte mazzo = new MazzoDiCarte();
        
        // Visualizza il mazzo ordinato
        System.out.println("Mazzo ordinato:");
        System.out.println(mazzo);

        // Mescola il mazzo
        mazzo.mescola();
        System.out.println("Mazzo mescolato:");
        System.out.println(mazzo);

        // Distribuisce alcune carte
        System.out.println("Carte distribuite:");
        for (int i = 0; i < 5; i++) {
            System.out.println(mazzo.distribuisci());
        }

        // Visualizza le carte rimanenti
        System.out.println("Carte rimanenti nel mazzo:");
        while (true) {
            try {
                System.out.println(mazzo.distribuisci());
            } catch (IllegalStateException e) {
                break;
            }
        }
    }
}