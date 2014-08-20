/*
 * Write your own atoi function
 */
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

using namespace std;

int my_atoi(const string &str)
{
    if (str.size() == 0) {
        throw invalid_argument("The input string cannot be empty");
    }

    int sgn = 1;
    int num = 0;
    auto it = begin(str);
    if (*it == '-') {
        sgn = -1;
        ++it;
    } else if (*it == '+'){
        ++it;
    }
    for (; it < end(str); ++it) {
        if (!isdigit(*it)) {
            throw invalid_argument("The input is invalid");
        }
        if (numeric_limits<int>::max() / 10 > num) {
            num *= 10;
        } else {
            throw logic_error("Overflow");
        }
        if (numeric_limits<int>::max() - (*it - '0') > num) {
            num += *it - '0';
        } else {
            throw logic_error("Overflow");
        }
    }
    return sgn * num;
}

int main()
{
    cout << my_atoi("12345") << endl;
    cout << my_atoi("-12345") << endl;
    cout << my_atoi("+0") << endl;
    return 0;
}
