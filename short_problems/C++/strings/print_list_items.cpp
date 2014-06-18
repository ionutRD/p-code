/**
 * Given a specific word and a list of items,
 * print all items which contain all characters
 * in the specific word
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const size_t NO_OF_CHARS = 256;

void print_items(const string & word, const vector<string> & items)
{
    char table[NO_OF_CHARS] = { 0 };
    int len = 0;

    for (char ch : word) {
        if (table[ch] == 0) {
            ++len;
            table[ch] = 1;
        }
    }

    for (string item : items) {
        int hits = 0;
        for (char ch : item)
            if (table[ch] == 1) {
                ++hits;
                table[ch] = 0;
            }
        if (hits == len)
            cout << item << endl;

        for (char ch : word)
            if (table[ch] == 0)
                table[ch] = 1;
    }
}


int main(int argc, char **argv)
{
    string word = "sun";
    vector<string> items = { "geeksforgeeks", "sunday", "utensils", "just", "sss" };
    cout << "Test1 : word = sun, items = {geeksforgeeks, sunday, utensils, just, sss} " << endl;
    print_items(word, items);
    return 0;
}
