/**
 * Find the majority element in a given array
 * The majority element appears more than n/2 + 1
 * where n is the number of elements in the array
 * The time complexity should be O(n)
 */
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

int majority(const vector<int> & arr)
{
    if (arr.size() == 0)
        throw invalid_argument("No majority element");

    int counter = 1;
    int candidate = arr.at(0);

    for (auto it = arr.begin() + 1; it != arr.end(); ++it) {
        if (*it == candidate)
            counter++;
        else
            counter--;
        if (counter <= 0)
            candidate = *it;
    }

    int real_count = count(arr.begin(), arr.end(), candidate);
    if (real_count < (arr.size() >> 1) + 1)
        throw invalid_argument("No majority element");

    return candidate;
}

int main(int argc, char **argv)
{
    cout << "Test 1: 1 1 2 1 1 3 1 4 => " << majority({1, 1, 2, 1, 1, 3, 1, 4}) << endl;
    cout << "Test 2: 1 2 0 2 2 3 2 => " << majority({1, 2, 0, 2, 2, 3, 2}) << endl;
    return 0;
}
