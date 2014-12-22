#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

pair<int,int> count_max_topic_teams(const vector<vector<bool>> &v)
{
    int max_ones = -1;
    int num_teams = 0;
    for (auto iti = v.begin(); iti != v.end() - 1; ++iti) {
        for (auto itj = iti + 1; itj != v.end(); ++itj) {
            vector<bool> result;
            result.reserve(iti->size());
            transform(iti->begin(), iti->end(), itj->begin(),
                    back_inserter(result), bit_or<bool>());
            int ones = accumulate(result.begin(), result.end(), 0);
            if (max_ones < ones) {
                num_teams = 1;
                max_ones = ones;
            } else if (max_ones == ones) {
                num_teams++;
            }
        }
    }
    return pair<int, int>(max_ones, num_teams);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> v;
    for (int i = 0; i < n; i++) {
        vector<bool> topics;
        string line;
        cin >> line;
        transform(line.begin(), line.end(),
                back_inserter(topics), [](char ch){return ch == '1';});
        v.push_back(topics);
    }
    pair<int, int> result = count_max_topic_teams(v);
    cout << result.first << endl;
    cout << result.second << endl;
    return 0;
}
