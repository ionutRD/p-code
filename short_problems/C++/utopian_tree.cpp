#include <iostream>
using namespace std;

int height(int n) {
    if (n == 0) {
        return 1;
    } else if (n & 1) {
        return (1 << (((n + 1) >> 1) + 1)) - 2;
    }
    return (1 << ((n >> 1) + 1)) - 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << height(n) << endl;
    }
}
