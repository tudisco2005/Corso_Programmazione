/*
Scrivere un programma Java che crei un oggetto di tipo String, contenente del
proprio nome, e stampi il primo e l’ultimo carattere della stringa. Descrivere ciò
che avviene in memoria durante l’esecuzione del programma, aiutandosi con un disegno
*/

public class Main {
    public static void main(String[] args) {
        String name = new String("Francesco");
        char[] chars = name.toCharArray();
        System.out.println(chars[0] + " " + chars[chars.length-1]);
    }
}