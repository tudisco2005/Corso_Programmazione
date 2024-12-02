
/*
Implementare la classe Contatore, definita qui sotto. Istanziarla e chiamarla da
una apposta classe starter contenente il main:
public class Contatore {
    int a;

    Contatore() {
        a=0; 
    }

    Contatore(int aa) {
        a=aa; 
    }

    void inc() {
        a=a+1;
    }

    void reset () {
        a=0; 
    }
}
*/

public class Starter {  
    public static void main(String[] args) {  
        Contatore n = new Contatore(10);
        System.out.println(n);
        n.inc();
        System.out.println(n);
    }  
} 