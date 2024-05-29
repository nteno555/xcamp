import java.util.Scanner;

public class HanoiTower {
    public static void moveFunc(int n, int currentRod, int newRod, int unusedRod) {
        if (n == 0) {}
        else {
            moveFunc(n-1, currentRod, unusedRod, newRod);
            System.out.print(currentRod);
            System.out.print(" ");
            System.out.print(newRod);
            System.out.println();
            moveFunc(n-1, unusedRod, newRod, currentRod);
        }
    }
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in); 
        int n = keyboard.nextInt();
        int total = (int)Math.pow(2, n) - 1;
        System.out.println(total);
        moveFunc(n, 1, 2, 3);
        keyboard.close();
    }
}
