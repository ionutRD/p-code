/**
 * Find the length of the longest
 * common substring.
 */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int lcs(const string &s1, const string &s2)
{
    int table[s1.size()][s2.size()];
    for (int i = 0; i < s1.size(); i++) {
        table[i][0] = (s1[i] == s2[0]);
    }
    for (int i = 0; i < s2.size(); i++) {
        table[0][i] = (s1[0] == s2[i]);
    }
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                table[i][j] = 1 + table[i - 1][j - 1];
            } else {
                table[i][j] = 0;
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (sol < table[i][j]) {
                sol = table[i][j];
            }
        }
    }
    return sol;
}

int main()
{
    cout << lcs("ACBBACC", "BACDCCACE") << endl;
    cout << lcs("AXYAXY", "AXBAX") << endl;
    return 0;
}
