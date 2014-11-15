import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class BinarySearchIterative {
    public static <T> boolean binarySearch(List<? extends T> list, T key, Comparator<? super T> comp) {
        if (list == null || key == null || comp == null) {
            throw new IllegalArgumentException("Arguments cannot be null");
        }
        int inf = 0;
        int sup = list.size() - 1;
        while (inf <= sup) {
            int mid = (inf + sup) >>> 1;
            final T midElement = list.get(mid);
            if (comp.compare(key, midElement) == 0) {
                return true;
            } else  if (comp.compare(key, midElement) < 0) {
                sup = mid - 1;
            } else {
                inf = mid + 1;
            }
        }
        return false;
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
