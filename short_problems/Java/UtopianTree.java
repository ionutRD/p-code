import java.util.Scanner;

public class UtopianTree {

    public static int height(int n) {
        if (n == 0) {
            return 1;
        } else if ((n & 1) == 1) {
            return (1 << (((n + 1) >> 1) + 1)) - 2;
        }
        return (1 << ((n >> 1) + 1)) - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++) {
            int n = sc.nextInt();
            System.out.println(height(n));
        }
    }

}
