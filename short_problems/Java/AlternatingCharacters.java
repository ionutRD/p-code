import java.util.Scanner;

public class AlternatingCharacters {
    public static int alternatingChars(String s) {
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++) {
            String s = sc.next();
            System.out.println(alternatingChars(s));
        }
    }
}
