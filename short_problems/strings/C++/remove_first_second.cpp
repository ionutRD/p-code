/**
 * Remove characters from the first string which are present
 * in the second string
 */
#include <iostream>
#include <string>
#include <array>

using namespace std;

const size_t NO_OF_CHARS = 256;

void remove_first_second(string & s1, const string & s2)
{
    array<size_t, NO_OF_CHARS> table { { 0 } };
    auto old_it = s1.begin();
    auto new_it = s1.begin();
    auto old_end = s1.end();

    for (char ch : s2)
        if (table.at(ch) == 0)
            table.at(ch) = 1;

    while (old_it != old_end) {
        if (table.at(*old_it) == 0) {
            *new_it = *old_it;
            ++new_it;
        }
        ++old_it;
    }

    s1.erase(new_it, old_end);
}

int main(int argc, char **argv)
{
    string s1 = "geeksforgeeks";
    string s2 = "doxologie";
    remove_first_second(s1, s2);
    cout << "Test 1 : s1 = geeksforgeeks, s2 = doxologie => " << s1 << endl;
    return 0;
}
