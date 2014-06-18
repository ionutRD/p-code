#include <iostream>
#include <cmath>
#include <cassert>
#include <stdexcept>

using namespace std;

const double EPS = 0.00000001;

double power_pos(double, int);

double power(double base, int exp)
{
    if (abs(base) < EPS && exp <= 0)
        throw invalid_argument("Mathematical exception");

    if (abs(base) < EPS)
        return 0.0;

    if (base == 1)
        return 1.0;

    if (exp < 0)
        return 1 / power_pos(base, -exp);
    return power_pos(base, exp);
}

double power_pos(double base, int exp)
{
    if (exp == 0)
        return 1;
    double hp = power_pos(base, exp >> 1);
    double result = hp * hp;

    if (exp & 1)
        result *= base;

    return result;
}

int main(int argc, char **argv)
{
    cout << "Test 1: pow(3, 4) = " << power(3, 4) << endl;
    assert(power(3, 4) == 81);
    cout << "Test 2: pow(5, 3) = " << power(5, 3) << endl;
    assert(power(5, 3) == 125);
    cout << "Test 2: pow(2, 10) = " << power(2, 10) << endl;
    assert(power(2, 10) == 1024);
    cout << "Test 3: pow(2, 11) = " << power(2, 11) << endl;
    assert(power(2, 11) == 2048);
    cout << "Test 4: pow(3, 3) = " << power(3, 3) << endl;
    assert(power(3, 3) == 27);
    cout << "Test 5: pow(1.5, 2) = " << power(1.5, 2) << endl;
    assert(power(1.5, 2) == 2.25);
    cout << "Test 6: pow(2, -3) = " << power(2, -3) << endl;
    assert(power(2, -3) == 0.125);
    cout << "Test 7: pow(1, 40) = " << power(1, 40) << endl;
    assert(power(1, 40) == 1);
    cout << "Test 8: pow(15, 0) = " << power(15, 0) << endl;
    assert(power(15, 0) == 1);
    cout << "Test 9: pow(34, 1) = " << power(34, 1) << endl;
    assert(power(34, 1) == 34);
    cout << "Test 10: pow(0, 100) = " << power(0, 100) << endl;
    assert(power(0, 100) == 0);
    try {
        cout << "Test 11: pow(0, 0) = " << power(0, 0) << endl;
        assert(true);
    } catch (const invalid_argument &exc) {
        cout << "Invalid" << endl;
        assert(true);
    }
    try {
        cout << "Test 12: pow(0, -2) = " << power(0, -2) << endl;
        assert(true);
    } catch (const invalid_argument &exc) {
        cout << "Invalid" << endl;
        assert(true);
    }
    cout << "Test 13: pow(-2, 6) = " << power(-2, 6) << endl;
    assert(power(-2, 6) == 64);
    cout << "Test 14: pow(-2, 5) = " << power(-2, 5) << endl;
    assert(power(-2, 5) == -32);
    cout << "Test 15: pow(-2, -1) = " << power(-2, -1) << endl;
    assert(power(-2, -1) == -0.5);
    return 0;
}
