import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

public class MergeSortRec {

    public static <T> void merge(List<T> l1, List<T> l2, Comparator<? super T> comp) {
        if (l1 == null || l2 == null || comp == null) {
            throw new IllegalArgumentException("Illegal arguments");
        }
        if (l1.size() == 0 || l2.size() == 0) {
            return;
        }

        int i = 0, j = 0;
        List<T> tmpList = new ArrayList<T>(l1.size() + l2.size());
        for (; i < l1.size() && j < l2.size();) {
            if (comp.compare(l1.get(i), l2.get(j)) < 0) {
                tmpList.add(l1.get(i++));
            } else {
                tmpList.add(l2.get(j++));
            }
        }
        for (; i < l1.size();) {
            tmpList.add(l1.get(i++));
        }
        for (; j < l2.size();) {
            tmpList.add(l2.get(j++));
        }
        i = 0;
        for (i = 0; i < l1.size(); i++) {
            l1.set(i, tmpList.get(i));
        }
        for (; i < tmpList.size(); i++) {
            l2.set(i - l1.size(), tmpList.get(i));
        }
    }

    public static <T> void mergeSortRec(List<T> list, Comparator<? super T> comp) {
        if (list == null || comp == null) {
            throw new IllegalArgumentException("Illegal arguments");
        }

        if (list.size() > 1) {
            int mid = list.size() >>> 1;
            mergeSortRec(list.subList(0, mid), comp);
            mergeSortRec(list.subList(mid, list.size()), comp);
            merge(list.subList(0, mid), list.subList(mid, list.size()), comp);
        }
    }

    public static void main(String[] args) {
        List<Integer> coll1 = Arrays.asList(1, 5, 8, 0, 3);
        mergeSortRec(coll1, Integer::compare);
        coll1.forEach(System.out::println);
    }
}
