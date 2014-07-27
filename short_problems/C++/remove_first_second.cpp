/**
 * Given two strings, remove characters in the
 * first string which are also present in the
 * second string.
 */
#include <iostream>
#include <string>
#include <array>

using namespace std;

const int NO_CHARS = 256;

void remove_first_second(string &first, const string &second)
{
    array<int, NO_CHARS> chars_tab{ {0} };

    for (auto ch : second) {
        chars_tab.at(ch) = 1;
    }

    int j = 0;
    for (auto ch : first) {
        if (chars_tab.at(ch) == 0) {
            first.at(j++) = ch;
        }
    }
    first.resize(j);
}

int main()
{
    string s1{"geeksforgeeks"};
    string s2{"ekonomi"};
    remove_first_second(s1, s2);
    cout << s1 << endl;
    return 0;
}
