#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        long long half = k >> 1;
        k & 1 ? cout << half * (half + 1) : cout << half * half;
        cout << endl;
    }
    return 0;
}
