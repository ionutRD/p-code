/**
 * Implement substr naive version.
 */
#include <string>
#include <iostream>

using namespace std;

auto substr(const string &str, const string &pat) -> decltype(begin(str))
{
    if (str.size() < pat.size()) {
        return end(str);
    }

    auto iti = begin(str);
    auto itj = begin(pat);
    while (iti != end(str)) {
        if (itj == end(pat)) {
            return iti - (itj - begin(pat));
        } else if (*iti == *itj) {
            ++iti;
            ++itj;
        } else {
            iti = iti - (itj - begin(pat)) + 1;
            itj = begin(pat);
        }
    }

    return end(str);

}

int main()
{
    string s1{"This is a test text."};
    string pat1{"text"};
    cout << substr(s1, pat1) - begin(s1) << endl;
    return 0;
}
