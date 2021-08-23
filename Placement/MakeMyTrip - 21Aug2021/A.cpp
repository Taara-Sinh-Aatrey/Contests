#include <bits/stdc++.h>
using namespace std;

#define int int64_t

int solve(int n, int m, vector<vector<int>> Edge) {
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u = Edge[i][0], v = Edge[i][1];
        --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    int ans = 0;
    
    for(int mask = 0; mask < 1 << n; mask++) {
        vector<int> col(n, -1);
        bool ok = true;
        for(int i = 0; i < n; i++) {
            if(mask >> i & 1) {
                if(col[i] == -1) {
                    function<bool(int)> dfs = [&](int u) {
                        for(auto& v : g[u]) {
                            if(!(mask >> v & 1)) continue;
                            if(col[v] == col[u]) return false;
                            if(col[v] == -1) {
                                col[v] = 1 - col[u];
                                dfs(v);
                            }
                        }
                        
                        return true;
                    };
                    col[i] = 0;
                    ok = ok & dfs(i);
                }
            }    
        }
        
        if(ok) {
            ans = max<int>(ans, __builtin_popcount(mask));
        }
    }
    
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> Edge(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> Edge[i][0] >> Edge[i][2];
    }
    
    cout << solve(n, m, Edge) << '\n';
    
    return 0;
}