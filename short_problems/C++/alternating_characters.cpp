#include <iostream>
#include <string>
using namespace std;

int altern_chars(const string &s) {
    int count = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s.at(i) == s.at(i - 1)) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << altern_chars(s) << endl;
    }
    return 0;
}
