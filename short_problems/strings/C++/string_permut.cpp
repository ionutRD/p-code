/**
 * Write a C++ to print all permutations
 * of a given string
 */
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

void do_permut_str(string::iterator &, string::iterator &, string::iterator &);

void swap_str(string::iterator & i, string::iterator & j)
{
    char tmp = *i;
    *i = *j;
    *j = tmp;
}

void permut_str(string & str)
{
        auto start = str.begin();
        auto end = str.end();
        do_permut_str(start, start, end);
}

void do_permut_str(string::iterator & k, string::iterator & begin, string::iterator & end)
{
    if (k == end) {
        ostream_iterator<char> out_it(cout, "");
        copy(begin, end, out_it);
        cout << endl;
        return;
    }

    for (auto i = k; i != end; ++i) {
        swap_str(i, k);
        auto next_it = k + 1;
        do_permut_str(next_it, begin, end);
        swap_str(i, k);
    }
}

int main(int argc, char **argv)
{
    string str("abc");
    permut_str(str);
    return 0;
}
