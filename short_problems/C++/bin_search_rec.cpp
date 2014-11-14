#include <iostream>
#include <vector>

using namespace std;

template <typename InputIt, typename T, typename Comp>
bool binary_search(InputIt first, InputIt last, const T &key)
{
    if (first == last) {
        return false;
    }
    auto middle = first + (last - first) / 2;
    if (Comp(key, *middle) == 0) {
        return true;
    } else if (Comp(key, *middle) < 0) {
        return binary_search(first, middle, key);
    } else return binary_search(middle, last, key);
}

int main()
{
    vector<int> coll1 {1, 5, 7, 11, 12};
    int key1 = 5;
    cout << binary_search(begin(coll1), end(coll1), key1) << endl;
    int key2 = 4;
    cout << binary_search(begin(coll1), end(coll1), key2) << endl;
    int key3 = 12;
    cout << binary_search(begin(coll1), end(coll1), key3) << endl;
    vector<int> coll2 {1, 5, 7, 11, 12, 15};
    int key4 = 6;
    cout << binary_search(begin(coll2), end(coll2), key4) << endl;
    return 0;
}
