import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class BubbleSort {

    public static <T> void bubbleSort(List<? extends T> list, Comparator<? super T> comp) {
        boolean sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 0; i < list.size() - 1; i++) {
                if (comp.compare(list.get(i), list.get(i + 1)) > 0) {
                    Collections.swap(list, i, i + 1);
                    sorted = false;
                }
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> coll1 = Arrays.asList(1, 5, 8, 0, 3);
        bubbleSort(coll1, Integer::compare);
        coll1.forEach(System.out::println);
    }
}
