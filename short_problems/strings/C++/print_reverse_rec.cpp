/**
 * Print the reverse of a string recursively
 */
#include <iostream>
#include <string>

using namespace std;

void print_reverse_rec_aux(string::iterator & it, string::iterator & end)
{
    if (it != end) {
        print_reverse_rec_aux(it + 1, end);
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
    return 0;
}
