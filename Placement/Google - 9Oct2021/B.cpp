#include "bits/stdc++.h"
using namespace std;

const int inf = 1e9 + 5;

int main() {
    int n, m;
    cin >> n;
    vector<int> out(n + 1);
    for (int i = 0; i <= n; i++) cin >> out[i];
    vector<int> in(n + 1);
    for (int i = 0; i <= n; i++) cin >> in[i];
    cin >> m;
    vector<vector<int>> g(n), rg(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        rg[v].emplace_back(u);
    }
    
    vector<int> topo;
    vector<bool> vis(n, false);

    function<void(int)> Dfs = [&](int u) {
        vis[u] = true;
        for (auto& v: g[u]) {
            if(!vis[v]) {
                Dfs(v);
            }
        }
        topo.emplace_back(u);
    };

    for(int u = 0; u < n; u++) {
        if(!vis[u]) {
            Dfs(u);
        }
    } 
    reverse(topo.begin(), topo.end());
    
    int mn;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        mn = min(mn, in[u]);
        for (auto& v: rg[u]) {
            if(!vis[v]) {
                dfs(v);
            }
        }
    };

    vis.assign(n, false);
    int ans = 0;
    auto ntopo = topo;   
    for(auto u: ntopo) {
        if(!vis[u]) {
            mn = inf;
            dfs(u);
            Dfs(u);
            ans += mn + out[n];
        }
    }
    cout << ans << '\n';
    return 0;
}