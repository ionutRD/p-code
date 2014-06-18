/**
 * Print duplicates of a string
 */
#include <iostream>
#include <string>
#include <array>

using namespace std;

const size_t NO_OF_CHARS = 256;

void solution(const string & str)
{
    array<int, NO_OF_CHARS> table { { 0 } };

    for (char ch : str)
        ++table.at(ch);

    for (auto it = table.begin(); it != table.end(); ++it)
        if (*it > 0)
            cout << "Character " << (char) (it - table.begin()) << " appears " << *it << " times." << endl;
}

int main(int argc, char **argv)
{
    solution(string("geeksforgeeks"));
    return 0;
}
