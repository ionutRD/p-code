/**
 * Rearrange an array such that
 * positives to come first and negative last
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void rearrange(vector<int> & arr)
{
    auto new_it = arr.begin();

    for (auto it = arr.begin(); it < arr.end(); ++it)
        if (*it > 0) {
            int tmp = *it;
            *it = *new_it;
            *new_it = tmp;
            ++new_it;
        }
}

int main(int argc, char **argv)
{
    vector<int> arr1 = {1, 9, -1, -3, 6, 4};
    cout << "Test 1: arr = {1, 9, -1, -3, 6, 4} =>" << endl;
    rearrange(arr1);
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    vector<int> arr2 = {-1, 9, -1, -3, 6, -4};
    cout << "Test 2: arr = {-1, 9, -1, -3, 6, -4} =>" << endl;
    rearrange(arr2);
    copy(arr1.begin(), arr1.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
