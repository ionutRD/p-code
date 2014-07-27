/**
 * Permute an iterable collection
 */
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

template <class ForwardIt>
void permute_aux(ForwardIt first, ForwardIt last, ForwardIt k)
{
    typedef typename ForwardIt::value_type value_type;
    if (k == last) {
        copy(first, last, ostream_iterator<value_type>(cout));
        cout << endl;
    }
    auto i = k;
    while (i < last) {
        iter_swap(k, i);
        permute_aux(first, last, k + 1);
        iter_swap(k, i);
        ++i;
    }
}

template <class Iterable>
void permute(Iterable &collection)
{
    permute_aux(begin(collection), end(collection), begin(collection));
}

int main()
{
    string s1{"abc"};
    permute(s1);
    return 0;
}
