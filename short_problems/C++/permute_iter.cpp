/**
 * Generate all permutations iteratively.
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>

using namespace std;

template <class Iterable>
void permute(Iterable &collection)
{
    typedef decltype(begin(collection)) iterator_type;
    typedef typename iterator_type::value_type value_type;

    /**
     * Check for empty collection.
     */
    if (begin(collection) == end(collection)) {
        return;
    }

    auto it = begin(collection);
    stack<iterator_type> st;
    st.push(it);
    while (!st.empty()) {
        if (it < end(collection)) {
            iter_swap(it, st.top());
            st.push(++it);
        } else if (it == end(collection)) {
            copy(begin(collection), end(collection), ostream_iterator<value_type>(cout, ""));
            cout << endl;
            --it;
            st.pop();
            while (!st.empty() && st.top() == end(collection) - 1) {
                iter_swap(it--, st.top());
                st.pop();
            }
            if (st.empty()) {
                break;
            }
            auto pos = st.top();
            iter_swap(it, pos);
            st.pop();
            st.push(pos + 1);
        }
    }
}

int main()
{
    string s1{"ABCD"};
    permute(s1);
    string s2{"A"};
    permute(s2);
    string s3{""};
    permute(s3);
    return 0;
}
