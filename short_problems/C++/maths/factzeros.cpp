/**
 * Find the number of zeros n! ends
 */
#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

int fact_zeros_end(int n)
{
    int zeros = 0;

    if (n < 0)
        throw invalid_argument("Argument must be positive");

    if (n < 5)
        return 0;

    for (int i = 0; i <= n; i += 5) {
        int tmp = i;
        while (tmp && tmp % 5 == 0) {
            tmp /= 5;
            ++zeros;
        }
    }

    return zeros;
}

int main(int argc, char **argv)
{
    cout << "Test 1: zeros(1!) = " << fact_zeros_end(1) << endl;
    assert(fact_zeros_end(1) == 0);
    cout << "Test 2: zeros(2!) = " << fact_zeros_end(2) << endl;
    assert(fact_zeros_end(2) == 0);
    cout << "Test 3: zeros(3!) = " << fact_zeros_end(3) << endl;
    assert(fact_zeros_end(3) == 0);
    cout << "Test 4: zeros(4!) = " << fact_zeros_end(4) << endl;
    assert(fact_zeros_end(4) == 0);
    cout << "Test 5: zeros(5!) = " << fact_zeros_end(5) << endl;
    assert(fact_zeros_end(5) == 1);
    cout << "Test 6: zeros(6!) = " << fact_zeros_end(6) << endl;
    assert(fact_zeros_end(6) == 1);
    cout << "Test 7: zeros(25!) = " << fact_zeros_end(25) << endl;
    assert(fact_zeros_end(25) == 6);
    cout << "Test 8: zeros(0!) = " << fact_zeros_end(0) << endl;
    assert(fact_zeros_end(0) == 0);
    try {
        cout << "Test 9: zeros(-1!) = " << fact_zeros_end(-1) << endl;
        assert(false);
    } catch (const invalid_argument & exc) {
        cout << "Invalid " << endl;
        assert(true);
    }

    return 0;
}
