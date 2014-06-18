/**
 * Convert a string into its int representation
 */
#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <climits>

using namespace std;

int my_atoi(const string & str)
{
    int sgn = 1;
    auto it = str.begin();
    int num = 0;

    if (*it == '-') {
        sgn = -1;
        ++it;
    } else if (*it == '+') {
        sgn = 1;
        ++it;
    }

    for (; it != str.end(); ++it)
        if (*it >= '0' && *it <= '9') {
            if (num > INT_MAX / 10)
                throw invalid_argument("Overflow");
            num *= 10;

            if (num > INT_MAX - (*it - '0'))
                throw invalid_argument("Overflow");
            num += *it - '0';
        } else
            throw invalid_argument("Invalid format");

    num *= sgn;
    return num;
}

int main(int argc, char **argv)
{
    cout << "Test 1: n = '1234' => " << my_atoi("1234") << endl;
    cout << "Test 2: n = '-1234' => " << my_atoi("-1234") << endl;
    cout << "Test 3: n = '0' => " << my_atoi("0") << endl;
    return 0;
}
