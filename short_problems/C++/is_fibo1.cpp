#include <iostream>

using namespace std;

bool is_fibo(unsigned long long num)
{
    if (num == 0 || num == 1) {
        return true;
    }
    unsigned long long prev = 0;
    unsigned long long crt = 1;
    while (crt < num) {
        unsigned long long tmp = crt;
        crt += prev;
        prev = tmp;
    }

    return num == crt;
}

int main()
{
    int num_cases;
    cin >> num_cases;
    for (int i = 0; i < num_cases; i++) {
        unsigned long long num;
        cin >> num;
        if (is_fibo(num)) {
            cout << "IsFibo" << endl;
        } else {
            cout << "IsNotFibo" << endl;
        }
    }
    return 0;
}
