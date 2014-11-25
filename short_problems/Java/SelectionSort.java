import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SelectionSort {

    public static <T> int argMin(List<? extends T> list, Comparator<? super T> comp, int index) {
        if (list == null || comp == null || index < 0) {
            throw new IllegalArgumentException("Illegal arguments");
        }
        int minIndex = index;
        for (int i = index; i < list.size(); i++) {
            if (comp.compare(list.get(i), list.get(minIndex)) < 0) {
                minIndex = i;
            }
        }
        return minIndex;
    }

    public static <T> void selectionSort(List<? extends T> list, Comparator<? super T> comp) {
        if (list == null || comp == null) {
            throw new IllegalArgumentException("Illegal arguments");
        }
        for (int i = 0; i < list.size(); i++) {
            int minIndex = argMin(list, comp, i);
            Collections.swap(list, i, minIndex);
        }
    }

    public static void main(String[] args) {
        List<Integer> coll1 = Arrays.asList(1, 5, 8, 0, 3);
        selectionSort(coll1, Integer::compare);
        coll1.forEach(System.out::println);
    }

}
