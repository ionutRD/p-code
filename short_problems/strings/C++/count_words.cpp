/**
 * Count words in a given string
 * Words are separated by any '\n', '\t' or space
 */
#include <iostream>
#include <string>

using namespace std;

const bool IN_WORD = true;
const bool OUT_WORD = false;

bool is_in_word(char ch)
{
    if (ch != '\n' && ch != '\t' && ch != ' ')
        return true;
    return false;
}

int count_words(const string & str)
{
    bool state = OUT_WORD;
    int count = 0;

    for (char ch : str)
        if (state == OUT_WORD && is_in_word(ch)) {
            ++count;
            state = IN_WORD;
        } else if (state == IN_WORD && !is_in_word(ch))
            state = OUT_WORD;

    return count;
}

int main(int arc, char **argv)
{
    cout << "Test1: ana     are mere  => " << count_words("ana      are  mere  ") << endl;
    return 0;
}
