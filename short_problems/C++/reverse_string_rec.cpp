/**
 * Reverse a string recursively.
 */
#include <iostream>
#include <string>

using namespace std;

string reverse_string(string::iterator first, string::iterator last) {
    if (first == last) {
        return "";
    }
    string partial = reverse_string(first + 1, last);
    partial.insert(end(partial), *first);
    return partial;
}

int main()
{
    string s1{"geeksforgeeks"};
    cout << reverse_string(s1.begin(), s1.end()) << endl;
    string s2{"a"};
    cout << reverse_string(s2.begin(), s2.end()) << endl;
    return 0;
}
