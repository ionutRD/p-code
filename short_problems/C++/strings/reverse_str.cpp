/**
 * Reverse a given string
 */
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

void strrev(string &str)
{
    auto iti = str.begin();
    auto itj = str.end() - 1;

    while (iti < itj) {
        char tmp = *iti;
        *iti = *itj;
        *itj = tmp;
        ++iti;
        --itj;
    }
}

int main(int argc, char **argv)
{
    string s1 = "abc";
    strrev(s1);
    cout << "Test 1: rev(abc) = " << s1 << endl;
    assert(s1 == string("cba"));
    string s2 = "ana are mere";
    strrev(s2);
    cout << "Test 2: rev(ana are mere) = " << s1 << endl;
    assert(s2 == string("erem era ana"));
    return 0;
}
