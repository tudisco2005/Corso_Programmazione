public class UniqueListArray {
    private char[] chars;
    private int max_size;
    private int i;

    public UniqueListArray(int size) {
        this.chars = new char[size];
        this.max_size = size;
        this.i = 0;
    }

    public UniqueListArray(char[] charArray) {
        this(charArray.length);
        for(char elm: charArray) {
            this.add(elm);
        }
    }

    public UniqueListArray(String input) {
        this(input.length()); // Chiamata al costruttore principale per inizializzare l'array
        for (char c : input.toCharArray()) {
            add(c); // Aggiunge ogni carattere, ignorando i duplicati
        }
    }

    public boolean add(char value) {
        if(i > max_size) System.out.println("array is full");
        for(int x=0; x<i; x++) {
            if(this.chars[x] == value) {
                System.out.println("value is alredy present");
                return false;
            }
        }

        this.chars[i] = value;
        i += 1;
        return true;
    }

    public char getindex(int index) {
        if(index < 0 || index > max_size) System.out.println("index, Out of boundes");
        return chars[index];
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        for (int x = 0; x < i; x++) {
            sb.append(chars[x]);
            if (x < max_size - 1) sb.append(", ");
        }
        sb.append("]");
        return sb.toString();
    }
}   