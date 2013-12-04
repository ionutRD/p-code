/**
 * Print permutation with repetition
 * e.g. str = ab => aa ab ba bb
 */
#include <iostream>
#include <string>

using namespace std;

void do_permut_repet(string & perm, int k, const string & str)
{
    if (k == perm.size()) {
        cout << perm << endl;
        return;
    }

    for (char ch : str) {
        perm[k] = ch;
        do_permut_repet(perm, k + 1, str);
    }
}

void permut_repet(const string & str)
{
    string tmp{ str };
    do_permut_repet(tmp, 0, str);
}

int main(int argc, char **argv)
{
    cout << "Test 1: str = 'abc' =>" << endl;
    permut_repet("abc");
    return 0;
}
