/**
 * Rearrange a vector so that negative and positive
 * number should alternate
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void rearrange(vector<int> & arr)
{
    auto new_it = arr.begin();

    for (auto it = arr.begin(); it != arr.end(); ++it)
        if (*it < 0) {
            int tmp = *new_it;
            *new_it = *it;
            *it = tmp;
            ++new_it;
        }

    auto neg_it = arr.begin();
    auto pos_it = new_it;

    while (pos_it != arr.end() && *neg_it < 0) {
        int tmp = *pos_it;
        *pos_it = *neg_it;
        *neg_it = tmp;
        ++pos_it;
        neg_it += 2;
    }
}

int main(int argc, char **argv)
{
    vector<int> arr = {1, 9, -1, -3, 6, 4};
    cout << "Test 1: arr = {1, 9, -1, -3, 6, 4} => " << endl;
    rearrange(arr);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
