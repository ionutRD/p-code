/**
 * Given an array of integers where all numbers
 * appear even times except one. Find the number that
 * appears odd times
 */
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int find_odd_times(const vector<int> &ary)
{
    int odd_times = 0;
    int count_result = 0;
    if (!(ary.size() & 1))
        throw invalid_argument("Invalid_argument");

    odd_times = accumulate(ary.begin(), ary.end(), odd_times, [](int x, int y) { return x ^ y; });

    count_result = count(ary.begin(), ary.end(), odd_times);
    if (count_result & 1)
        return odd_times;
    else
        throw invalid_argument("Invalid input");
}

int main(int argc, char **argv)
{
    vector<int> arr1 = {1,2,1,1,2,3,3};
    cout << "Test 1: {1,2,1,1,2,3,3,} = " << find_odd_times(arr1) << endl;
    assert(find_odd_times(arr1) == 1);
    vector<int> arr2 = {1,2,1,1,2,3,3,1,2};
    cout << "Test 2: {1,2,1,1,2,3,3,1,2} = " << find_odd_times(arr2) << endl;
    assert(find_odd_times(arr2) == 2);
    vector<int> arr3 = {1,2,0,1,2};
    cout << "Test 3: {1,2,0,1,2} = " << find_odd_times(arr3) << endl;
    assert(find_odd_times(arr3) == 0);
    vector<int> arr4 = {0,1,2,3,3,2,1,0};
    try {
        cout << "Test 4: {0,1,2,3,3,2,1,0} = " << find_odd_times(arr4) << endl;
        assert(false);
    } catch (const invalid_argument  &exc) {
        cout << "Invalid" << endl;
        assert(true);
    }
    vector<int> arr5 = {1,2,3,4,5,6,7,8,9,8};
    try {
        cout << "Test 5: {1,2,3,4,5,6,7,8,9} = " << find_odd_times(arr5) << endl;
        assert(false);
    } catch (const invalid_argument  &exc) {
        cout << "Invalid" << endl;
        assert(true);
    }
    vector<int> arr6 = {-1,-2,-1,-1,-2,-1,-2,3,3};
    cout << "Test 6: {-1,-2,-1,-1,-2,-1,-2,3,3} = " << find_odd_times(arr6) << endl;
    assert(find_odd_times(arr6) == -2);
    return 0;
}
