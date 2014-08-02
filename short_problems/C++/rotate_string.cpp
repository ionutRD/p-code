/**
 * Rotate an iterable collection
 * by k positions.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template<class T>
int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

template<class Iterable>
void rotate(Iterable &collection, int k)
{
    k = sgn(k) * (abs(k) % collection.size());
    if (k == 0 ) {
        return;
    }
    int shift = k > 0 ? k : collection.size() + k;

    reverse(begin(collection), end(collection));
    reverse(begin(collection), begin(collection) + shift);
    reverse(begin(collection) + shift, end(collection));
}


int main()
{
    string str1{"abcde"};
    rotate(str1, -1);
    cout << str1 << endl;
    return 0;
}
