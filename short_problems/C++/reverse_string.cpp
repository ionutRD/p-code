/**
 * Reverse a string in place.
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;

template <class Iterable>
void reverse(Iterable &collection)
{
    auto it_begin = begin(collection);
    auto it_end = end(collection);
    while ((it_begin != it_end) && (it_begin != --it_end)) {
        iter_swap(it_begin++, it_end);
    }
}

int main()
{
    string s1{"geeksforgeeks"};
    reverse(s1);
    cout << s1 << endl;
    string s2{"a"};
    reverse(s2);
    cout << s2 << endl;;
    return 0;
}
