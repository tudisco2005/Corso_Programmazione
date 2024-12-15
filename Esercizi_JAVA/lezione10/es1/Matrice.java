import java.util.Arrays;

public class Matrice {
    private int[][] matrix;

    // Constructor that initializes a matrix with given size
    public Matrice(int size_x, int size_y) {
        this.matrix = new int[size_x][size_y];
    }

    // Constructor that initializes the matrix with an input 2D array
    public Matrice(int[][] input) {
        this.matrix = input;
    }

    // Get element at position (x, y)
    public int getInt(int x, int y) {
        return this.matrix[x][y];
    }

    // Set element at position (x, y) with a given value
    public void setInt(int x, int y, int value) {
        this.matrix[x][y] = value;
    }

    // Get the number of rows in the matrix
    public int getSize() {
        return matrix.length; // Fix: length is not a method
    }

    // Get the number of columns in the matrix
    public int getSizeline() {
        return matrix[0].length; // Fix: length is not a method
    }

    // Add two matrices and return the resulting matrix
    public Matrice somma(Matrice to_add) {
        // Fix: Correct the spelling of 'length'
        Matrice tmp = new Matrice(to_add.getSize(), to_add.getSizeline());
        for (int x = 0; x < to_add.getSize(); x++) {
            for (int y = 0; y < to_add.getSizeline(); y++) {
                tmp.setInt(x, y, to_add.getInt(x, y) + this.matrix[x][y]);
            }
        }
        return tmp;
    }

    // Multiply two matrices and return the resulting matrix
    public Matrice moltiplicazione_tra_matrici(Matrice to_multiply) {
        // Fix: Correct the spelling of 'length'
        Matrice tmp = new Matrice(this.getSize(), to_multiply.getSizeline());
        for (int x = 0; x < this.getSize(); x++) {
            for (int y = 0; y < to_multiply.getSizeline(); y++) {
                int res = 0;
                for (int n = 0; n < to_multiply.getSize(); n++) {
                    res += this.matrix[x][n] * to_multiply.getInt(n, y);
                }
                tmp.setInt(x, y, res);
            }
        }
        return tmp;
    }

    // Multiply the matrix by a scalar
    public Matrice moltiplicazione_con_scalare(int k) {
        Matrice tmp = new Matrice(this.getSize(), this.getSizeline());
        for (int x = 0; x < this.getSize(); x++) {
            for (int y = 0; y < this.getSizeline(); y++) {
                tmp.setInt(x, y, this.matrix[x][y] * k);
            }
        }
        return tmp;
    }

    @Override
    public String toString() {
        StringBuilder stringed = new StringBuilder("{");
        for (int x = 0; x < this.getSize(); x++) {
            stringed.append("{");
            for (int y = 0; y < this.getSizeline(); y++) {
                stringed.append(this.matrix[x][y]);
                if (y < this.getSizeline() - 1) {
                    stringed.append(", ");
                }
            }
            stringed.append("}");
            if (x < this.getSize() - 1) {
                stringed.append(", ");
            }
        }
        stringed.append("}");
        return stringed.toString();
    }
}
