import java.util.*;
public class Q1_primeNos {
    public static boolean isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter n and m: ");
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        System.out.println("Prime numbers between " + n + " and " + m + " are:");
        for (int i = n; i <= m; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        scanner.close();
    }
}