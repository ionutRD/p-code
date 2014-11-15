#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename InputIt, typename T, typename Compare = less<T>>
bool bin_search(InputIt first, InputIt last, const T &key, Compare comp = Compare())
{
    while (first < last && first + 1 < last) {
        auto middle = first + (distance(first, last) >> 1);
        if (key == *middle) {
            return true;
        } else if (comp(key, *middle)) {
            last = middle;
        } else {
            first = middle;
        }
    }

    return false;
}

int main()
{
    vector<int> coll1 {1, 5, 7, 11, 12};
    int key1 = 5;
    cout << bin_search(begin(coll1), end(coll1), key1) << endl;
    int key2 = 4;
    cout << bin_search(begin(coll1), end(coll1), key2) << endl;
    int key3 = 12;
    cout << bin_search(begin(coll1), end(coll1), key3) << endl;
    vector<int> coll2 {1, 5, 7, 11, 12, 15};
    int key4 = 6;
    cout << bin_search(begin(coll2), end(coll2), key4) << endl;
    vector<int> coll3 {};
    int key5 = 5;
    cout << bin_search(begin(coll3), end(coll3), key5) << endl;
    return 0;
}
