/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 04:46:58
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    const int lvl = 19;
    
    vector<vector<int>> p(lvl, vector<int>(n, -1));
    vector<int> depth(n, 0);
    
    function<void(int, int)> dfs = [&] (int u, int par) {
        p[0][u] = par;
        depth[u] = par == -1 ? 0 : depth[par] + 1;
        
        for (auto& v : g[u]) {
            if (v == par) continue;
            dfs(v, u);
        }    
    };
    dfs(0, -1);
    

    for (int i = 1; i < lvl; i++) {
        for (int node = 0; node < n; node++) {
            if (p[i - 1][node] != -1) {
                p[i][node] = p[i - 1][p[i - 1][node]];
            }
        }
    }
    
    auto go_up = [&] (int node, int dis) {
        for (int i = lvl - 1; i >= 0; i--)
            if (node >= 0 && (dis >> i & 1))
                node = p[i][node];
        return node;
    };
    
    auto find_lca = [&](int u, int v) {
        if (depth[u] > depth[v]) { 
            swap(u, v);
        }

        v = go_up(v, depth[v] - depth[u]);

        if (u == v) 
            return u;

        for (int i = lvl - 1; i >= 0; i--) {
            if (p[i][u] != p[i][v]){
                u = p[i][u];
                v = p[i][v];
            }
        }
        return p[0][u];
    };
    
    vector<vector<bool>> a(2, vector<bool>(n));
    for (int i = 0; i < 2; i++) {
        int sz;
        cin >> sz;
        while (sz--) {
            int x;
            cin >> x, --x;
            a[i][x] = true;
            int y = go_up(x, d);
            if (y != -1) {
                a[i ^ 1][y] = true;
            }
        }
    }
    
    function<void(int, int)> Dfs = [&] (int u, int par) {
        for (auto& v : g[u]) {
            if (v == par) continue;
            Dfs(v, u);
            for (int i = 0; i < 2; i++) {
                a[i][u] = a[i][u] | a[i][v];
            }
        }
    };
    Dfs(0, -1);
    
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < n; j++) {
            ans += a[i][j] ? 2 : 0;
        }
    }
    
    cout << ans;
    
    return 0;
}