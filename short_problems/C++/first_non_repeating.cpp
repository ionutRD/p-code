/**
 * Find the first non-repeating character from a string.
 */
#include <iostream>
#include <algorithm>
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
    char char_pos[NO_CHARS] = { 0 };
    fill_n(char_pos, NO_CHARS, -1);
    for (int i = 0; i < str.size(); i++) {
        if (char_pos[str.at(i)] == -1) {
            char_pos[str.at(i)] = i;
        } else if (char_pos[str.at(i)] >= 0) {
            char_pos[str.at(i)] = -2;
        }
    }

    char first_non_repeating;
    int min_index = INT_MAX;
    for (int i = 0; i < NO_CHARS; i++) {
        if (char_pos[i] >= 0 && min_index > char_pos[i]) {
            min_index = char_pos[i];
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
