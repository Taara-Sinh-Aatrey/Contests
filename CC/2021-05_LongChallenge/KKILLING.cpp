#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(int tt) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<int> mn(n, 1e9), mx(n, -1e9);

    function<void(int, int)> dfs = [&](int u, int par) {
        int child = 0;
        for(int v: g[u]) {
            if(v == par) continue;
            child++;
            dfs(v, u);
            mn[u] = min(mn[u], mx[v]);
            mx[u] = max(mx[u], mx[v]);
        }
        
        if(child == 0) {
            mn[u] = mx[u] = 0;
            return; 
        }

        if(mn[u] == mx[u]) {
            mn[u]++;
            mx[u] = mn[u];
        } else {
            mn[u]++;
            mx[u] = mn[u] + 1;
        }
    };

    dfs(0, -1);

    int days = mn[0];
    vector<int> ans;

    function<void(int, int, int)> validate = [&](int u, int par, int least) {
        int child = 0;
        int nleast = min(least, mn[u]);
        for(int v: g[u]) {
            if(v == par) continue;
            child++;
            if(u == 0) {
                if(mx[v] + 1 == mn[u]) {
                    validate(v, u, nleast);
                }
            } else {
                if(mx[v] + 1 > nleast || mx[u] == mn[u]) {
                    validate(v, u, nleast);
                }
            }
        }
        
        if(child == 0) {
            ans.emplace_back(u);
        }
    };

    validate(0, -1, days);

    cout << ans.size() << " " << days << '\n';
    sort(ans.begin(), ans.end());
    for(auto& u: ans) {
        cout << u + 1 << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
    

    return 0;
}