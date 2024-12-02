/*
Creare una Figura fatta da 2 cerchi e tre linee. 
Verificare se Figura contiene cerchi concentrici e linee che si intersecano tra loro, tramite apposito main.
Verificare se le tre linee costituiscono un triangolo. 
*/

public class Main {
    public static void main(String[] args) {
        // Creazione dei cerchi
        Cerchio cerchio1 = new Cerchio(new Vett(0, 0), 5);
        Cerchio cerchio2 = new Cerchio(new Vett(0, 0), 3);

        // Creazione delle linee
        Linea linea1 = new Linea(new Vett(0, 0), new Vett(4, 4));
        Linea linea2 = new Linea(new Vett(0, 4), new Vett(4, 0));
        Linea linea3 = new Linea(new Vett(2, 5), new Vett(2, -1));

        // Creazione della figura
        Figura figura = new Figura(cerchio1, cerchio2, linea1, linea2, linea3);

        // Stampa dello stato della figura
        System.out.println(figura);

        // Verifica dei cerchi concentrici
        System.out.println("I cerchi sono concentrici? " + figura.cerchiConcentrici());

        // Verifica dell'intersezione delle linee
        System.out.println("Le linee si intersecano? " + figura.lineeSiIntersecano());

        // Verifica se le linee formano un triangolo
        System.out.println("Le linee formano un triangolo? " + figura.formanoTriangolo());
    }
}
