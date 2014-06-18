/**
 * Given an array of integers remove duplicates
 * from the given array
 * Example: {1, 12, 1, 3, 1, 4, 3} => {1, 12, 3, 4}
 */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>

using namespace std;

void uniq(vector<int> & arr)
{
    unordered_set<int> table;

    auto old_index = arr.begin();
    auto new_index = arr.begin();
    auto table_end = table.end();

    while(old_index < arr.end()) {
        if (table.find(*old_index) == table_end) {
            table.insert(*old_index);
            *new_index = *old_index;
            ++new_index;
        }
        ++old_index;
    }

    arr.resize(new_index - arr.begin());
}

int main(int argc, char **argv)
{
    vector<int> arr = {1, 2, 1, 4, 2, 5, 1};
    cout << "Test 1: arr = {1, 2, 1, 4, 2, 5, 1} => ";
    uniq(arr);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}
