#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename RandomIt, typename Compare = less<typename RandomIt::value_type>>
void selection_sort(RandomIt first, RandomIt last, Compare comp = Compare())
{
    for (auto it = first; it != last; ++it) {
        iter_swap(it, min_element(it, last, comp));
    }
}

int main()
{
    vector<int> coll1 {1, 5, 8, 0, 3, 2};
    selection_sort(begin(coll1), end(coll1));
    copy(begin(coll1), end(coll1), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> coll2 {1};
    selection_sort(begin(coll2), end(coll2));
    copy(begin(coll2), end(coll2), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> coll3 {};
    selection_sort(begin(coll3), end(coll3));
    copy(begin(coll3), end(coll3), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
