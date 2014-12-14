#include <iostream>

using namespace std;

int max_xor(int left, int right)
{
    int xorred = left ^ right;
    int num_bits = 0;
    while (xorred) {
        xorred >>= 1;
        num_bits++;
    }
    return (1 << num_bits) - 1;
}

int main()
{
    int res, left, right;
    cin >> left;
    cin >> right;
    res = max_xor(left, right);
    cout << res;
    return 0;
}
