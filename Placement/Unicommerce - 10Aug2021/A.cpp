#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }
    
    const int lvl = 19;
    
    vector<vector<int>> p(lvl, vector<int>(n, -1));
    vector<int> depth(n, 0), wt(n, 0);
    
    function<void(int, int)> dfs = [&](int u, int par) {
        p[0][u] = par;
        depth[u] = par == -1 ? 0 : depth[par] + 1;
        
        for(auto& [w, v] : g[u]) {
            if(v == par) continue;
            wt[v] = wt[u] + w;
            dfs(v, u);
        }    
    };
    dfs(0, -1);
    

    for(int i = 1; i < lvl; i++){
        for(int node = 0; node < n; node++){
            if(p[i - 1][node] != -1){
                p[i][node] = p[i - 1][p[i - 1][node]];
            }
        }
    }
    
    auto get = [&](int node, int dis) {
        for (int i = lvl - 1; i >= 0; i--)
            if (dis >> i & 1) 
                node = p[i][node];
        return node;
    };
    
    auto find_lca = [&](int u, int v) {
        if (depth[u] > depth[v]) { 
            swap(u, v);
        }

        v = get(v, depth[v] - depth[u]);

        if (u == v) 
            return u;

        for (int i = lvl - 1; i >= 0; i--){
            if (p[i][u] != p[i][v]){
                u = p[i][u];
                v = p[i][v];
            }
        }
        return p[0][u];
    };
    
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v, --u, --v;
        int lca = find_lca(u, v);
        cout << lca + 1 << " " << max(wt[u], wt[v]) - wt[lca] + 1 << '\n';
    }
    
    return 0;
}