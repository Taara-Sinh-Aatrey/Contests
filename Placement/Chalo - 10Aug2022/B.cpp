#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    vector<array<int, 2>> dp(n);
    
    function<void(int, int)> dfs = [&] (int u, int par) {
        auto &me = dp[u];
        me[0] = 1;
        int extra = inf; // so that no camera is needed on itself
        for (auto &v : g[u]) {
            if (v == par)
                continue;
            dfs(v, u);
            auto &he = dp[v];
            me[0] += min(he[0], he[1]);
            me[1] += he[0];
        }
    };
    dfs(0, -1);
    
    cout << min(dp[0][0], dp[0][1]) << endl;
    
    return 0;
}