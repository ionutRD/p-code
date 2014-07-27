/**
 * Remove all duplicates from a given string.
 */
#include <iostream>
#include <string>
#include <array>

using namespace std;

const int NO_CHARS = 256;

void remove_all_duplicates(string &str)
{
    array<int, NO_CHARS> char_tab{ {0} };
    int j = 0;
    for (auto ch : str) {
        if (char_tab.at(ch) == 0) {
            str.at(j++) = ch;
            char_tab.at(ch) = 1;
        }
    }
    str.resize(j);
}

int main()
{
    string s1{"geeksforgeeks"};
    remove_all_duplicates(s1);
    cout << s1 << endl;
    string s2{"aaaaa"};
    remove_all_duplicates(s2);
    cout << s2 << endl;
    return 0;
}
