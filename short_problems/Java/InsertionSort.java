import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class InsertionSort {

    public static <T> void insertionSort(List<T> list, Comparator<? super T> comp) {
        if (list == null || comp == null) {
            throw new IllegalArgumentException("Illegal arguments");
        }

        for (int i = 0; i < list.size(); i++) {
            T crtElem = list.get(i);
            int j = i;
            while (j > 0 && comp.compare(crtElem, list.get(j - 1)) < 0) {
                list.set(j, list.get(j - 1));
                j--;
            }
            list.set(j, crtElem);
        }
    }

    public static void main(String[] args) {
        List<Integer> coll1 = Arrays.asList(1, 5, 8, 0, 3);
        insertionSort(coll1, Integer::compare);
        coll1.forEach(System.out::println);
    }
}
