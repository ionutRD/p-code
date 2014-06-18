/**
 * Print permutations in lexicographic order
 */
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

void do_permut_lexi(string & str, int k,
        const string & ord, unordered_set<char> & table)
{
    if (k == str.size())
        cout << str << endl;

    for (char ch : ord)
        if (table.find(ch) == table.end()) {
            table.insert(ch);
            str[k] = ch;
            do_permut_lexi(str, k + 1, ord, table);
            table.erase(ch);
        }

}

void permut_lexi(const string & str)
{
    string ord{ str };
    string tmp{ str };
    unordered_set<char> table;
    sort(ord.begin(), ord.end());
    do_permut_lexi(tmp, 0, ord, table);
}

int main(int argc, char **argv)
{
    cout << "Test 1: str = 'bcad' =>" << endl;
    permut_lexi("bcad");
    return 0;
}
