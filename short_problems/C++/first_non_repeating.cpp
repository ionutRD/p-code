/**
 * Find the first non-repeating character from a string.
 */
#include <array>
#include <iostream>
#include <climits>
#include <stdexcept>
#include <string>

using namespace std;

const size_t NO_CHARS = 256;

char find_first_non_repeating(const string &str)
{
    if (str.size() == 0) {
        throw invalid_argument("The string cannot be empty");
    }
    array<int, NO_CHARS> char_pos;
    char_pos.fill(-1);
    for (int i = 0; i < str.size(); i++) {
        if (char_pos.at(str.at(i)) == -1) {
            char_pos.at(str.at(i)) = i;
        } else if (char_pos.at(str.at(i)) >= 0) {
            char_pos.at(str.at(i)) = -2;
        }
    }

    char first_non_repeating;
    int min_index = INT_MAX;
    for (int i = 0; i < NO_CHARS; i++) {
        if (char_pos.at(i) >= 0 && min_index > char_pos.at(i)) {
            min_index = char_pos.at(i);
            first_non_repeating = static_cast<char>(i);
        }
    }

    return first_non_repeating;
}

int main()
{
    cout << find_first_non_repeating("geeksforgeeks") << endl;
    cout << find_first_non_repeating("geeksquiz") << endl;
    return 0;
}
