#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int compute_unfairness(vector<int> &v, int k) {
    sort(v.begin(), v.end());
    int unfairness = numeric_limits<int>::max();
    auto inf = v.begin();
    auto sup = v.begin() + k - 1;
    while (sup < v.end()) {
        int diff = *sup - *inf;
        if (unfairness > diff) {
            unfairness = diff;
        }
        ++inf;
        ++sup;
    }
    return unfairness;
}

int main() {
    int N, K, unfairness;
    cin >> N >> K;
    vector<int> candies;
    for (int i=0; i<N; i++) {
        int candy;
        cin >> candy;
        candies.push_back(candy);
    }

    unfairness = compute_unfairness(candies, K);

    cout << unfairness << "\n";
    return 0;
}
