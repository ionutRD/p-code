#include <iostream>

using namespace std;

int solve(int n, int c, int m)
{
    int total = n / c;
    int wrappers = total;
    while (wrappers >= m) {
        int new_chocolate = wrappers / m;
        total += new_chocolate;
        wrappers = wrappers % m + new_chocolate;
    }
    return total;
}

int main()
{
    int t, n, c, m;
    cin >> t;
    while (t--) {
        cin >> n >> c >> m;
        cout << solve(n, c, m) << endl;
    }
    return 0;
}
