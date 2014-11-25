#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename RandomIt, typename Compare = less<typename RandomIt::value_type>>
void merge(RandomIt first1, RandomIt last1, RandomIt first2, RandomIt last2, Compare comp = Compare())
{
    if (first1 == last1 || first2 == last2) {
        return;
    }
    auto len1 = distance(first1, last1), len2 = distance(first2, last2);
    typedef typename RandomIt::value_type value_type;
    vector<value_type> tmp_coll;
    tmp_coll.reserve(len1 + len2);
    auto i = first1, j = first2, k = begin(tmp_coll);
    for (; i != last1 && j != last2; ++k) {
        if (comp(*i, *j)) {
            *k = *i;
            ++i;
        } else {
            *k = *j;
            ++j;
        }
    }
    k = copy(i, last1, k);
    copy(j, last2, k);

    k = begin(tmp_coll);
    copy(k, k + len1, first1);
    copy(k + len1, k + len1 + len2, first2);
}

template <typename RandomIt, typename Compare = less<typename RandomIt::value_type>>
void merge_sort(RandomIt first, RandomIt last, Compare comp = Compare())
{
    if (distance(first, last) > 1) {
        auto middle = first + (distance(first, last) >> 1);
        merge_sort(first, middle, comp);
        merge_sort(middle, last, comp);
        merge(first, middle, middle, last, comp);
    }
}

int main()
{
    vector<int> coll1 = {1, 5, 8, 0, 3, 2};
    merge_sort(begin(coll1), end(coll1), less<int>());
    copy(begin(coll1), end(coll1), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> coll2 = {6, 4};
    merge_sort(begin(coll2), end(coll2), less<int>());
    copy(begin(coll2), end(coll2), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> coll3 = {1};
    merge_sort(begin(coll3), end(coll3), less<int>());
    copy(begin(coll3), end(coll3), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
