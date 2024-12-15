/*
Scrivere un programma Java che riceva un stringa da input e stampi la stringa
ottenuta invertendo la prima e l’ultima lettera.
*/

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner userinput = new Scanner(System.in);  // Create a Scanner object
        System.out.print("Enter input: ");

        String input = userinput.nextLine();  // Read user input

        char[] chars = input.toCharArray();

        char tmp = chars[0];
        chars[0] = chars[chars.length - 1];
        chars[chars.length - 1] = tmp;

        System.out.println(chars);
    }
}