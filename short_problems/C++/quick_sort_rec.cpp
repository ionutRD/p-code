#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template<class Iterator>
Iterator partition(Iterator first, Iterator last) {
    if (first + 1 == last) {
        return first;
    }
    auto pivot_val = *first;
    iter_swap(first, last - 1);
    auto inf = first;
    auto sup = last - 2;
    while (inf <= sup) {
        if (*inf > pivot_val) {
            iter_swap(inf, sup);
            sup--;
        } else {
            inf++;
        }
    }
    iter_swap(inf, last - 1);
    return inf;
}

template<class Iterator>
void quickSort(Iterator first, Iterator last) {
    if (first < last) {
        auto pivot_it = partition(first, last);
        quickSort(first, pivot_it);
        quickSort(pivot_it + 1, last);
    }
}

int main(void) {
   vector<int> v;
   int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    quickSort(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;
}
