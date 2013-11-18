/**
 * Print the reverse of a string recursively
 */
#include <iostream>
#include <string>

using namespace std;

void print_reverse_rec_aux(string::iterator & it, string::iterator & end)
{
    if (it != end) {
        auto it_next = it + 1;
        print_reverse_rec_aux(it_next, end);
        cout << *it;
    }
}

void print_reverse_rec(string & str)
{
    auto it_i = str.begin();
    auto it_f = str.end();
    print_reverse_rec_aux(it_i, it_f);
}

int main(int argc, char **argv)
{
    string s = "geeksforgeeks";
    cout << "Test 1: geeksforgeeks => " << endl;
    print_reverse_rec(s);
    cout << endl;
    string s2 = "ana are mere";
    cout << "Test 1: ana are mere => " << endl;
    print_reverse_rec(s2);
    cout << endl;
    return 0;
}
