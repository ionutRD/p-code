#include <iostream>
#include <vector>

using namespace std;

template <typename InputIt, typename T>
InputIt linear_search(InputIt first, InputIt last, const T &key)
{
    for (; first != last; ++first) {
        if (*first == key) {
            return first;
        }
    }

    return last;
}

int main()
{
    vector<int> coll1 {1, 5, 7, 0, -1, 8, 17};
    int key1 = 0;
    cout << linear_search(begin(coll1), end(coll1), key1) - begin(coll1) << endl;
    int key2 = 9;
    cout << linear_search(begin(coll1), end(coll1), key2) - begin(coll1) << endl;
    int key3 = 17;
    cout << linear_search(begin(coll1), end(coll1), key3) - begin(coll1) << endl;
    return 0;
}


