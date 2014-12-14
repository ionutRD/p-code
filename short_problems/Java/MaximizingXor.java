import java.util.Scanner;

public class MaximizingXor {
    public static int maximizeXor(int left, int right) {
        int xorred = left ^ right;
        int numBits = 0;
        while (xorred != 0) {
            xorred >>= 1;
            numBits ++;
        }
        return (1 << numBits) - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int left = sc.nextInt();
        int right = sc.nextInt();
        System.out.println(maximizeXor(left, right));
    }
}
