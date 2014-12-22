#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int n) {
    int p = 0, q = -1;
    p = n / 3;
    while (p >= 0) {
        int k = n - p - (p << 1);
        if (k % 5 == 0) {
            q = k / 5;
            break;
        } else {
            p--;
        }
    }
    if (q == -1) {
        cout << -1 << endl;
    } else {
        p += p << 1;
        q += q << 2;
        for (int i = 0; i < p; i++) {
            cout << 5;
        }
        for (int i = 0; i < q; i++) {
            cout << 3;
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
