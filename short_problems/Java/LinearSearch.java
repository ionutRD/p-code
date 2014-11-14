import java.util.Arrays;
import java.util.Collection;

public class LinearSearch {
    public static <T> boolean linearSearch(Collection<? extends T> collection, T key) {
        for (T it : collection) {
            if (it.equals(key)) {
                return true;
            }
        }

        return false;
    }
    public static void main(String[] args) {
        final Collection<Integer> coll1 = Arrays.asList(1, 4, 2, 5, 8, -1);
        final int key1 = 2;
        System.out.println(linearSearch(coll1, key1));
        final int key2 = 3;
        System.out.println(linearSearch(coll1, key2));
    }
}
