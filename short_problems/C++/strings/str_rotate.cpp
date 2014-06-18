/**
 * Rotate a given string with k >= 0
 * For example: str = 'abcd', k = 1 => str = dabc
 */
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void str_reverse(string & str, int i, int j)
{
    if (i < 0 || j >= str.size())
        return;

    auto left = str.begin() + i;
    auto right = str.begin() + j;

    while (left < right) {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        ++left;
        --right;
    }
}

void str_rotate(string & str, int k)
{
    if (k < 0)
        return;

    k %= str.size();

    str_reverse(str, 0, str.size() - 1);
    str_reverse(str, 0, k - 1);
    str_reverse(str, k, str.size() - 1);
}

int main(int arg, char **argv)
{
    string str = "abcd";
    cout << "Test 1: str = 'abcd', k = 1 => ";
    str_rotate(str, 1);
    cout << str << endl;
    return 0;
}
