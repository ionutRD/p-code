/**
 * Remove duplicate characters in a string
 * The time complexity should be O(n)
 */
#include <iostream>
#include <cassert>
#include <string>
#include <array>

using namespace std;

const size_t NO_OF_CHARS = 256;

void remove_dup(string & str)
{
    array<int, NO_OF_CHARS> table { { 0 } };
    auto init_it = str.begin();
    auto final_it = str.begin();
    auto end_it = str.end();

    while (init_it != end_it) {
        if (!table.at(*init_it)) {
            table.at(*init_it) = 1;
            *final_it = *init_it;
            ++final_it;
        }
        ++init_it;
    }

    str.erase(final_it, end_it);
}

int main(int argc, char **argv)
{
    string s1 = "geeksforgeeks";
    remove_dup(s1);
    cout << "Test 1: geeksforgeeks = " << s1 << endl;
    string s2 = "ana are mere";
    remove_dup(s2);
    cout << "Test 1: ana are mere = " << s2 << endl;
    return 0;
}
