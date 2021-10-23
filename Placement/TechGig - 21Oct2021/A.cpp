#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, h;
    cin >> n >> h;
    vector<bool> hideout(n, false);
    for (int i = 0; i < h; i++) {
        int u;
        cin >> u, --u;
        hideout[u] = true;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> sz(n);
    vector<int> dp(n);
    function<void(int, int)> dfs = [&](int u, int par) {
        sz[u] += hideout[u];
        for(auto& v : g[u]) {
            if(v == par) continue;
            dfs(v, u);
            int pairs = max<int>(0, sz[v] - h / 2);
            dp[v] += sz[v] - 2 * pairs;
            sz[u] += sz[v];
            dp[u] += dp[v];
        }
    };
    dfs(0, -1);
    cout << dp[0];
    return 0;
}