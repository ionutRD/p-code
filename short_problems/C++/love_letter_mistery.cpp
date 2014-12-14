#include <iostream>
#include <string>
using namespace std;

inline int abs(char x) {
    return x < 0 ? -x : x;
}

int find_min_operations(const string &s)
{
    if (s.size() == 0 || s.size() == 1) {
        return 0;
    }
    auto inf = begin(s);
    auto sup = end(s) - 1;
    int count = 0;
    while (inf < sup) {
        count += abs(*inf - *sup);
        ++inf;
        --sup;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << find_min_operations(s) << endl;
    }
    return 0;
}

