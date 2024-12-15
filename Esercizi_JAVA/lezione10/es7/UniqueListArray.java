import java.util.Arrays;

public class UniqueListArray {
    private Object[] elements; // Array di oggetti generici
    private int max_size; // Dimensione massima dell'array
    private int size; // Numero attuale di elementi

    public UniqueListArray(int maxSize) {
        this.max_size = maxSize;
        this.elements = new Object[maxSize];
        this.size = 0;
    }

    public UniqueListArray(Object[] inputArray) {
        this(inputArray.length);
        for (Object elm : inputArray) {
            this.add(elm);
        }
    }

    public boolean add(Object value) {
        if (size >= max_size) {
            System.out.println("Array is full");
            return false;
        }

        // Controllo duplicati usando equals
        for (int x = 0; x < size; x++) {
            if (elements[x].equals(value)) {
                System.out.println("Value is already present");
                return false;
            }
        }

        elements[size] = value;
        size++;
        return true;
    }

    public Object get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return elements[index];
    }

    @Override
    public String toString() {
        return Arrays.toString(Arrays.copyOf(elements, size));
    }
}

class Fraction {
    private int numerator;
    private int denominator;

    public Fraction(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Fraction fraction = (Fraction) obj;
        return numerator == fraction.numerator && denominator == fraction.denominator;
    }

    @Override
    public int hashCode() {
        return 31 * numerator + denominator;
    }

    @Override
    public String toString() {
        return numerator + "/" + denominator;
    }
}