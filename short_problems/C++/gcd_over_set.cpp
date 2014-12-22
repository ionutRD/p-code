#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    while (b) {
        int aux = a;
        a = b;
        b = aux % b;
    }
    return a;
}

bool sherlock_and_gcd(const vector<int> &v) {
    if (v.size() == 1) {
        return *v.begin() == 1;
    }

    return accumulate(v.begin(), v.end(), 0, gcd) == 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int elem;
            cin >> elem;
            arr.push_back(elem);
        }
        if (sherlock_and_gcd(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
