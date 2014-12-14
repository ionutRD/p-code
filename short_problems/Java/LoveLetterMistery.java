import java.util.Scanner;

public class LoveLetterMistery {

    public static int findMinOps(String s) {
        if (s.length() == 0 || s.length() == 1) {
            return 0;
        }
        int inf = 0;
        int sup = s.length() - 1;
        int count = 0;
        while (inf < sup) {
            count += Math.abs(s.charAt(inf) - s.charAt(sup));
            inf++;
            sup--;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int i = 0; i < numCases; i++) {
            String s = sc.next();
            System.out.println(findMinOps(s));
        }
    }

}
