/**
 * Find the length of the longest
 * common subsequence.
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
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }
    return table[s1.size() - 1][s2.size() - 1];
}

int main()
{
    cout << lcs("ACBBACC", "BACDCCACE") << endl;
    return 0;
}
