#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename RandomIt, typename Compare = less<typename RandomIt::value_type>>
void insertion_sort(RandomIt first, RandomIt last, Compare comp = Compare())
{
    for (auto it = first; it != last; ++it) {
        auto crt_val = *it;
        auto jt = it;
        while (jt != first && comp(crt_val, *(jt - 1))) {
            *jt = *(jt - 1);
            --jt;
        }
        *jt = crt_val;
    }
}

int main()
{
    vector<int> coll1 {1, 5, 8, 0, 3, 2};
    insertion_sort(begin(coll1), end(coll1));
    copy(begin(coll1), end(coll1), ostream_iterator<int>(cout, " "));
    return 0;
}
