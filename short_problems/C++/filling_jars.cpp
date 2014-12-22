#include <iostream>

using namespace std;

int main()
{
    int m, n;
    long long sum = 0;
    cin >> n >> m;
    for (auto i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        sum += (b - a + 1) * static_cast<long long>(k);
    }
    cout << sum / n;
    return 0;
}
