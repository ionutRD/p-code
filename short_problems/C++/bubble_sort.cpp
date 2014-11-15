#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename RandomIt, typename Compare = less<typename RandomIt::value_type>>
void bubble_sort(RandomIt first, RandomIt last, Compare comp = Compare())
{
    if (first == last) {
        return;
    }
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (auto it = first; it != last - 1; ++it) {
            if (!comp(*it, *(it + 1))) {
                sorted = false;
                iter_swap(it, it + 1);
            }
        }
    }
}

int main()
{
    vector<int> coll1 {1, 5, 8, 0, 3, 2};
    bubble_sort(begin(coll1), end(coll1));
    copy(begin(coll1), end(coll1), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> coll2 {1};
    bubble_sort(begin(coll2), end(coll2));
    copy(begin(coll2), end(coll2), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> coll3 {};
    bubble_sort(begin(coll3), end(coll3));
    copy(begin(coll3), end(coll3), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
