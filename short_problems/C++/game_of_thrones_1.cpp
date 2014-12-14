#include <iostream>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

const int NUM_CHARS = 256;

bool can_be_palindrome(const string &s) {
    if (s.size() == 0 || s.size() == 1) {
        return true;
    }
    array<int, 26> char_tab = { 0 };
    for (auto ch : s) {
        char_tab[ch - 'a']++;
    }
    bool odd_found = false;
    bool odd_length = s.size() % 2 == 1;
    for (auto count : char_tab) {
        if (count % 2 == 1 && odd_length && !odd_found) {
            odd_found = true;
        } else if (count % 2 == 1) {
            return false;
        }
    }
    return true;
}

int main() {

    string s;
    cin>>s;

    int flag = 0;
    flag = static_cast<int>(can_be_palindrome(s));
    if(flag==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
