/**
 * Reverse a string recursively
 */
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

void strrev(string &str)
{
    if (str.size() == 0)
        return;

    string left = str.substr(1);
    strrev(left);
    str = left + str.substr(0, 1);
}

int main(int argc, char **argv)
{
    string s1 = "ana are mere";
    strrev(s1);
    cout << "Test 1: strrev(ana are mere) = " << s1 << endl;
    return 0;
}
