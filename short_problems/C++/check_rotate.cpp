/**
 * Given two strings find out that one string
 * is a rotation of the other.
 */
#include <string>
#include <iostream>

using namespace std;

bool check_rotate(const string &s1, const string &s2)
{
    return (s1 + s1).find(s2) != string::npos;
}

int main()
{
    cout << check_rotate("abcd", "cdab") << endl;
    return 0;
}
