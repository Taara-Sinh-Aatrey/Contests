/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.10.2022 07:49:49
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u != v)
            g[u].emplace_back(v);
    }
    vector<bool> vis(n), act(n);
    bool cyc = false;
    function<void(int)> dfs = [&] (int u) {
        vis[u] = true;
        act[u] = true;
        for (auto& v : g[u]) {
            if (act[v]) {
                cyc = true;
                return;
            }
            else if (!vis[v]) {
                dfs(v);
            }
        }
        act[u] = false;
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    cout << (cyc ? "Ineligible" : "Eligible");
    return 0;
}