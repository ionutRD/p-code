/**
 * Given two strings check if the are anagrams
 * of each other
 */
#include <array>
#include <iostream>
#include <string>

using namespace std;

const int NUM_CHARS = 256;

bool check_anagram(const string &str1, const string &str2)
{
    array<int, 256> chars_tab{ { 0 } };

    for (auto ch : str1) {
        chars_tab.at(ch)++;
    }

    for (auto ch : str2) {
        chars_tab.at(ch)--;
    }

    for (auto i : chars_tab) {
        if (i != 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << check_anagram("anagram", "mragnaa") << endl;
    cout << check_anagram("ana", "nna") << endl;
    return 0;
}
