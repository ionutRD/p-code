/**
 * Return the maximum occurring character
 * in a string.
 */
#include <stdexcept>
#include <string>
#include <iostream>
#include <array>

using namespace std;

const int NO_CHARS = 256;

char max_occurring_char(const string &str)
{
    if (str.empty()) {
        throw invalid_argument("Input string cannot be empty");
    }
    array<int, NO_CHARS> chars_tab{ {0} };

    for (auto ch : str) {
        chars_tab.at(ch)++;
    }

    int max_char = -1;
    char result;

    for (int i = 0; i < NO_CHARS; i++) {
        if (chars_tab.at(i) > max_char) {
            max_char = chars_tab.at(i);
            result = static_cast<char>(i);
        }
    }

    return result;
}

int main()
{
    cout << max_occurring_char("geeksforgeeks") << endl;
    cout << max_occurring_char("abcdefg") << endl;
    cout << max_occurring_char("aaabcc") << endl;
    return 0;
}
