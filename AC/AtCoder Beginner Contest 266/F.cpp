/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 18:20:53
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
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<bool> is_cyclic(n);
    {
        vector<bool> vis(n), act(n);
        vector<int> p(n, -1);
        function<void(int)> dfs = [&] (int u) {
            vis[u] = true;
            act[u] = true;
            for(auto& v : g[u]) {
                if (v == p[u]) continue;
                if (act[v]) {
                    // v -> ..... -> u -> v
                    int node = u;
                    while (true) {
                        is_cyclic[node] = true;
                        if (node == v) break;
                        node = p[node];
                    }
                }
                if (!vis[v]) {
                    p[v] = u;
                    dfs(v);
                }
            }
            act[u] = false;
        };
        dfs(0);
    }
    vector<int> roots(n);
    vector<bool> vis(n, false);
    vector<int> p(n, -1);
    function<void(int, int)> dfs = [&] (int root, int u) {
        roots[u] = root;
        vis[u] = true;
        for(auto& v : g[u]) {
            if (vis[v] || is_cyclic[v]) continue;
            dfs(root, v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (is_cyclic[i]) {
            dfs(i, i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v, --u, --v;
        cout << (roots[u] == roots[v] ? "Yes" : "No") << '\n';
    }
    return 0;
}