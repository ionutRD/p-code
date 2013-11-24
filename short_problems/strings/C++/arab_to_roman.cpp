/**
 * Conver a number from arab format into
 * roman formant
 * For example: num = 1918 => roman = MCMXVIII
 */
#include <string>
#include <stdexcept>
#include <iostream>
#include <tuple>

using namespace std;

string roman_unit(const tuple<char, char, char> & syms, unsigned int digit)
{
    if (digit == 0 || digit > 9)
        throw invalid_argument("Digit must be between 1 and 9");

    if (digit == 4 || digit == 9) {
        string roman(2, get<0>(syms));
        roman.at(1) = digit == 4 ? get<1>(syms) : get<2>(syms);
        return roman;
    }

    if (digit == 5) {
        string roman(1, get<1>(syms));
        return roman;
    }

    int addition = digit > 5 ? 1 : 0;
    int dim = digit > 5 ? digit + addition - 5 : digit;
    string roman(dim, get<0>(syms));
    if (digit > 5)
        roman.at(0) = get<1>(syms);
    return roman;
}

string arab_to_roman(unsigned int num)
{
    if (num == 0 || num > 3999)
        throw invalid_argument("The number cannot be represented in roman");

    char syms[][3] = {{'I', 'V', 'X'},
                      {'X', 'L', 'C'},
                      {'C', 'D', 'M'},
                      {'M', 'M', 'M'}};
    int div = 1000;
    int rank = 3;

    string roman = "";
    while (div >= 1) {
        int digit = num / div % 10;
        if (digit > 0) {
            string roman_digit = roman_unit(make_tuple(syms[rank][0], syms[rank][1], syms[rank][2]), digit);
            roman += roman_digit;
        }
        div /= 10;
        --rank;
    }

    return roman;
}

int main(int argc, char **argv)
{
    cout << "Test 1: n = 1918 => " << arab_to_roman(1918) << endl;
    cout << "Test 2: n = 2013 => " << arab_to_roman(2013) << endl;
    cout << "Test 3: n = 528 => " << arab_to_roman(528) << endl;
    return 0;
}
