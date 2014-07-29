/**
 * Reverse words in a text.
 * The text is separated with spaces.
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

enum class State
{
    IN_WORD,
    BETWEEN_WORDS
};

void reverse_words(string &text)
{
    /*
     * Reverse the entire text
     */
    reverse(begin(text), end(text));

    State currentState = State::BETWEEN_WORDS;
    auto startWord = begin(text);
    for (auto it = begin(text); it != end(text); ++it) {
        if (currentState == State::BETWEEN_WORDS && !isspace(*it)) {
            startWord = it;
            currentState = State::IN_WORD;
        } else if (currentState == State::IN_WORD && isspace(*it)) {
            reverse(startWord, it);
            currentState = State::BETWEEN_WORDS;
        }
    }
}

int main()
{
    string s1{"  This    is a  test string  "};
    reverse_words(s1);
    cout << s1 << endl;
    return 0;
}
