/*
 * Replace spaces with %20 in a given string.
 */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void replace_spaces(string &str)
{
    int no_of_spaces = count_if(begin(str), end(str),
            [](char c) { return c == ' ';});
    int sz = str.size();
    str.resize(sz + (no_of_spaces << 1));
    auto old_it = begin(str) + sz - 1;
    auto new_it = end(str) - 1;

    while (old_it >= begin(str)) {
        if (*old_it == ' ') {
            *new_it-- = '0';
            *new_it-- = '2';
            *new_it-- = '%';
        } else {
            *new_it-- = *old_it;
        }
        --old_it;
    }
}

int main()
{
    string str("This is a   test string. ");
    replace_spaces(str);
    cout << str << endl;
    return 0;
}
