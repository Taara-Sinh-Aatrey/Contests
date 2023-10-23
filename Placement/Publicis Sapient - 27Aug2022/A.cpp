#include "bits/stdc++.h"
using namespace std;

int maxPathSum(vector<int> parents, vector<int> values) {
#define int int64_t
    int n = values.size();
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        g[parents[i]].emplace_back(i);
    }
    const int inf = 1e9 + 5;
    vector<int> mx(n), smx(n);
    int ans = -inf;
    auto update = [&] (int u, int val) {
        if (val > mx[u]) {
            smx[u] = mx[u];
            mx[u] = val;
        }
        else if (val > smx[u]) {
            smx[u] = val;
        }
    };
    function<void(int, int)> dfs = [&] (int u, int par) {
        for (auto &v : g[u]) {
            dfs(v, u);
            update(u, mx[v]);
        }
        mx[u] += values[u];
        ans = max(ans, mx[u] + smx[u]);
    };
    dfs(0, -1);
    return ans;
#undef int
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << maxPathSum({-1, 0, 0, 2, 3}, {0, 4, 6, -11, 3}) << endl;
    cout << maxPathSum({-1, 0, 1, 2, 0}, {5, 7, -10, 4, 15}) << endl;
    cout << maxPathSum({-1, 0, 1, 2, 0}, {-2, 10, 10, -3, 10}) << endl;
    return 0;
}