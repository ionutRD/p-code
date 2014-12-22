#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int isqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int prev = n + 1;
    int x = n;
    while (x < prev) {
        prev = x;
        x = (x + n / x) >> 1;
    }
    return prev;
}

int count_squares(int a, int b) {
    int count = 0;
    int sq = isqrt(a);
    int x = sq * sq;
    if (x < a) {
        x += (sq << 1) + 1;
        sq++;
    }
    while (x <= b) {
        count++;
        x += (sq << 1) + 1;
        sq++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << count_squares(a, b) << endl;
    }
    return 0;
}
