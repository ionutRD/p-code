#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(int n, int a, int b) {
    int min = a < b ? a : b;
    int max = a > b ? a : b;
    int last_stone = (n - 1) * min;
    cout << last_stone << " ";
    if (a == b) {
        cout << endl;
        return;
    }
    int i = 0;
    while (i < n - 1) {
        last_stone += (max - min);
        cout << last_stone << " ";
        i++;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}
