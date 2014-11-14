import java.util.Arrays;
import java.util.Comparator;
import java.util.List;


public class BinarySearchRecursive {
    public static <T> boolean binarySearch(List<? extends T> list, T key, Comparator<? super T> comp) {
        if (list == null || key == null || comp == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
        return BinarySearchRecursive.<T>binarySearchAux(list, 0, list.size(), key, comp);
    }

    public static <T> boolean binarySearchAux(List<? extends T> list, int inf, int sup, T key, Comparator<? super T> comp) {
        if (inf == sup || inf + 1 == sup) {
            return false;
        }
        final int middle = inf + ((sup - inf) >>> 1);
        final T midElement = list.get(middle);
        if (comp.compare(key, midElement) == 0) {
            return true;
        } else if (comp.compare(key, midElement) < 0) {
            return binarySearchAux(list, inf, middle, key, comp);
        } else {
            return binarySearchAux(list, middle, sup, key, comp);
        }
    }

    public static void main(String[] args) {
        final List<Integer> list1 = Arrays.asList(1, 3, 5, 9, 13);
        final int key1 = 3;
        System.out.println(binarySearch(list1, key1, Integer::compare));
        final int key2 = 4;
        System.out.println(binarySearch(list1, key2, Integer::compare));
        final int key3 = 13;
        System.out.println(binarySearch(list1, key3, Integer::compare));
    }
}
