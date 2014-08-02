/**
 * Counts words in a given sentence.
 */
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

enum class State {
    IN_WORD,
    BETWEEN_WORDS
};

int count_words(const string &text)
{
    State currentState = State::BETWEEN_WORDS;
    int numOfWords = 0;
    for (auto ch : text) {
        if (currentState == State::BETWEEN_WORDS && !isspace(ch)) {
            currentState = State::IN_WORD;
            numOfWords++;
        } else if (currentState == State::IN_WORD && isspace(ch)) {
            currentState = State::BETWEEN_WORDS;
        }
    }
    return numOfWords;

}

int main()
{
    cout << count_words("  This is    a test      text\n   ") << endl;
    return 0;
}
