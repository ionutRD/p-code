#include <cstdlib>
#include <iostream>

using namespace std;

int isqrt(int n)
{
    if (n == 0 || n == 1) {
        return n;
    }
    int prev = n + 1;
    int x = n;
    while (prev > x) {
        prev = x;
        x = (x + n / x) >> 1;
    }
    return prev;
}


int main()
{
    int n;
    cin >> n;
    cout << isqrt(n);
    return 0;
}
