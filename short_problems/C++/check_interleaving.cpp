/**
 * Check if a string is an interleaving
 * of other two.
 */
#include <iostream>
#include <string>

using namespace std;

bool check_interleaving(const string &str,
                        const string &s1,
                        const string &s2)
{
    auto iti = begin(s1);
    auto itj = begin(s2);
    if (str.size() != s1.size() + s2.size()) {
        return false;
    }
    for (auto ch : str) {
        if (*iti == ch) {
            ++iti;
        } else if (*itj == ch) {
            ++itj;
        } else {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << check_interleaving("ekonomi", "kmi", "eono") << endl;
    return 0;
}
