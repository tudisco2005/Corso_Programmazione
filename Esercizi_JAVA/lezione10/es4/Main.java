/*
Scrivere un metodo statico Java che legga da tastiera una stringa e stampi la
stringa invertita.
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner userinput = new Scanner(System.in);  // Create a Scanner object
        System.out.print("Enter input: ");

        String input = userinput.nextLine();  // Read user input

        char[] chars = input.toCharArray();

        for(int i=0;i<chars.length/2; i++) {
            char tmp = chars[i];
            chars[i] = chars[chars.length - 1 - i];
            chars[chars.length - 1 - i] = tmp;
        }
        System.out.println(chars);
    }
}