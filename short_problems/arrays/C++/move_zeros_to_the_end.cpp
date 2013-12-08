/**
 * Move all zeros to the end of the array
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void move_zeros(vector<int> & arr)
{
    auto new_it = arr.begin();
    auto old_it = arr.begin();

    for (; old_it != arr.end(); ++old_it)
        if (*old_it != 0) {
            *new_it = *old_it;
            ++new_it;
        }

    for (; new_it != arr.end(); ++new_it)
        *new_it = 0;
}

int main(int argc, char **argv)
{
    vector<int> arr = { 1, 0, -1, 0, 0, 2};
    cout << "Test 1: arr = {1, 0, -1, 0, 0, 2} => " << endl;
    move_zeros(arr);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
