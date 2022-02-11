#include "bits/stdc++.h"
using namespace std;

#define int int64_t

int inverse(int a, int m) {
    if(a == 0) return 0;
    int MOD = m;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    u %= MOD;
    if(u < 0) u += MOD;
    return u;
}

void solve() {
    const int mod = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    assert(m == n - 1);
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    function<pair<int, int>(int, int)> dfs = [&] (int node, int parent) -> pair<int, int> {
        int ans = 1, sz = 0;
        for (auto &neighbor : g[node]) {
            if (neighbor == parent)
                continue;
            pair<int, int> cur = dfs(neighbor, node);
            ans = ans * cur.first % mod;
            ans = ans * fact[sz + cur.second] % mod;
            ans = ans * inverse(fact[sz], mod) % mod;
            ans = ans * inverse(fact[cur.second], mod) % mod;
            sz += cur.second;
        }
        sz++;
        return pair(ans, sz);
    };
    cout << dfs(0, -1).first << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}