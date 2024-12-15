/*
Scrivere un programma Java che legga in input da tastiera una stringa e resti-
tuisca in output su video la stringa ottenuta trasformando la stringa in caratteri
maiuscoli.
*/

import java.util.Scanner;  // Import the Scanner class

public class Main {
    public static void main(String[] args) {
        Scanner userinput = new Scanner(System.in);  // Create a Scanner object
        System.out.print("Enter input: ");

        String input = userinput.nextLine();  // Read user input
        System.out.println("To uppercase: " + input.toUpperCase());  // Output user input
    }
}
