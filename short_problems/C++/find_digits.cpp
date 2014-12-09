#include <iostream>

using namespace std;

int find_digits(long long num) {
    int count = 0;
    long long tmp = num;
    while(tmp) {
        int digit = tmp % 10;
        if (digit) {
            count += num % digit == 0;
        }
        tmp /= 10;
    }
    return count;
}

int main()
{
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++) {
        long long num;
        cin >> num;
        cout << find_digits(num) << endl;
    }
    return 0;
}
