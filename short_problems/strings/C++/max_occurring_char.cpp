/**
 * Get the maximum occurring char in a given string
 */
#include <string>
#include <iostream>
#include <cassert>
#include <array>

using namespace std;

const size_t NO_OF_CHARS = 256;

char get_max_occurring_char(const string &str)
{
    array<int, NO_OF_CHARS> table{ { 0 } };
    int max_idx = -1, max_val = -1;

    for (char ch : str)
        ++table.at(ch);

    for (auto it = table.begin(); it != table.end(); ++it)
        if (max_val < *it) {
            max_val = *it;
            max_idx = it - table.begin();
        }

    return max_idx;
}

int main(int argc, char **argv)
{
    cout << "Test 1: test string = " << get_max_occurring_char("test string") << endl;
    assert(get_max_occurring_char("test string") == 't');
    cout << "Test 2: test string = " << get_max_occurring_char("ana are mere") << endl;
    assert(get_max_occurring_char("ana are mere") == 'a');
    return 0;
}
