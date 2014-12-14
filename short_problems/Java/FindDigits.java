import java.util.Scanner;

public class FindDigits {

    public static int findDigits(long num) {
        int count = 0;
        long tmp = num;
        while (tmp != 0) {
            long digit = tmp % 10;
            if (digit != 0) {
                count += num % digit == 0 ? 1 : 0;
            }
            tmp /= 10;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++) {
            long num = sc.nextLong();
            System.out.println(findDigits(num));
        }
    }
}
