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

    @Override
    public String toString() {
        return String.valueOf(a);
    }
}
