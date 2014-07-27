#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void divide_n_parts(const string &str, size_t n)
{
    if (n == 0) {
        throw invalid_argument("Argument n cannot be 0");
    }
    if (str.size() % n != 0) {
        throw invalid_argument("The size of the string is not multiple of n");
    }

    for (int i = 0; i < str.size(); i++) {
        if (i % n == 0 && i) {
            cout << endl;
        }
        cout << str.at(i);
    }
}

int main()
{
    divide_n_parts("thisisastrin", 4);
    return 0;
}
