/**
 * Given two strings print all interleavings
 * of the given strings
 */
#include <iostream>
#include <string>

using namespace std;

void do_print_all_interleavings(string::const_iterator & s1,
                                string::const_iterator &s2,
                                string &istr, int m, int n, int i)
{
    if (m == 0 && n == 0)
        cout << istr << endl;

    if (m != 0) {
        istr[i] = *s1;
        auto next_s1 = s1 + 1;
        do_print_all_interleavings(next_s1, s2, istr, m - 1, n, i + 1);
    }

    if (n != 0) {
        istr[i] = *s2;
        auto next_s2 = s2 + 1;
        do_print_all_interleavings(s1, next_s2, istr, m, n - 1, i + 1);
    }
}

void print_all_interleavings(const string & s1, const string & s2)
{
    string s = s1 + s2;
    auto bs1 = s1.cbegin();
    auto bs2 = s2.cbegin();
    do_print_all_interleavings(bs1, bs2, s, s1.size(), s2.size(), 0);
}

int main(int argc, char **agrv)
{
    cout << "Test 1: s1 = 'AB', s2 = 'CD' =>" << endl;
    print_all_interleavings("AB", "CD");
    return 0;
}
