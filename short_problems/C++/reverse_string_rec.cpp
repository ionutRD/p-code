/**
 * Reverse a string recursively.
 */
#include <iostream>
#include <string>

using namespace std;

template<class ForwardIt>
void print_reverse(ForwardIt first, ForwardIt last) {
    if (first != last) {
        print_reverse(first + 1, last);
        cout << *first;
    }
}

int main()
{
    string s1{"geeksforgeeks"};
    print_reverse(s1.begin(), s1.end());
    cout << endl;
    string s2{"a"};
    print_reverse(s2.begin(), s2.end());
    return 0;
}
