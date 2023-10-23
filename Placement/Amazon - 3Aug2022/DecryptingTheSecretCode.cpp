#include "bits/stdc++.h"
using namespace std;

template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }

vector<int> solve(int n, vector<vector<int>> pairs) {
    int m = pairs.size();
    sort(pairs.begin(), pairs.end(), [&] (auto &x, auto &y) {
        return x[1] - x[0] > y[1] - y[0];
    });
    vector<int> endPoint(n + 1, -1), startPoint(n + 1, n + 1);
    function<void(int, int)> Insert = [&] (int start, int end) -> void {
        int pend = endPoint[start];
        int pstart = startPoint[end];
        endPoint[start] = end;
        startPoint[end] = start;
        if (pend > end) {
            Insert(end + 1, pend);
        }
        if (pstart < start) {
            Insert(pstart, start - 1);
        }
    };
    for (int i = 0; i < m; i++) {
        Insert(pairs[i][0], pairs[i][1]);
    }
    vector<int> ans;
    vector<vector<int>> prs;
    for (int start = 1; start <= n; start++) {
        if (endPoint[start] == start) {
            ans.emplace_back(start);
        }
    }
    return ans;
}

int main() {
    cout << solve(4, {{1, 3}, {1, 2}, {4, 4}}) << endl; // [3, 4]
    cout << solve(3, {{1, 3}, {2, 2}, {1, 2}}) << endl; // [1, 2, 3]
    cout << solve(4, {{1, 3}, {2, 3}, {2, 4}}) << endl; // [1, 4]
    return 0;
}