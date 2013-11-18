/**
 * Check if two strings are rotations of each other
 */
#include <iostream>
#include <string>

using namespace std;

bool is_rot(const string & s1, const string & s2)
{
    if (s1.size() != s2.size())
        return false;

    string aux = s1 + s1;

    return aux.find(s2) != string::npos;
}

int main(int argc, char **argv)
{
    cout << "Test 1: s1 = ABCD, s2 = CDAB => " << is_rot("ABCD", "CDAB") << endl;
    cout << "Test 2: s1 = ABCD, s2 = BCAD => " << is_rot("ABCD", "BCAD") << endl;
    return 0;
}
