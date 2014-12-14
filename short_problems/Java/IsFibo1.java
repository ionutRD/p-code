import java.util.Scanner;

public class IsFibo1 {

    public static boolean isFibo(long num) {
        if (num == 0 || num == 1) {
            return true;
        }
        long prev = 0;
        long crt = 1;
        while (crt < num) {
            long tmp = crt;
            crt += prev;
            prev = tmp;
        }

        return num == crt;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++) {
            long num = sc.nextLong();
            if (isFibo(num)) {
                System.out.println("IsFibo");
            } else {
                System.out.println("IsNotFibo");
            }
        }
    }
}
