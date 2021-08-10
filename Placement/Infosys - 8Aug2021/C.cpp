#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

void solve() {
    
    int n, k;
    cin >> n >> k, --k;
    
    vector<vector<int>> g(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        
        if(p[i] != -1) {
            p[i]--;
            g[p[i]].emplace_back(i);
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(k + 1));
    vector<int> d(n, INF);
    
    function<void(int)> dfs = [&](int u) {
        if(g[u].empty()) {
            dp[u][0]++;
            dp[u][min<int>(1, k)]++;
            d[u] = 1;
            return;
        }
        
        for(int i = k; i >= 0; i--)  {
            dp[u][i] = 1;
        }
        
        for(auto& v : g[u]) {
            dfs(v);
            
            if(k == 0) {
                dp[u][0] *= dp[v][0];
                dp[u][0] %= mod;
            }
            else {
                d[u] = min(d[u], d[v] + 1);
                for(int i = k; i >= 1; i--) {
                    dp[v][i - 1] += dp[v][i];
                    dp[v][i - 1] %= mod;
                    
                    dp[u][i] *= dp[v][i - 1];
                    dp[u][i] %= mod;
                }
                
                dp[u][0] *= dp[v][k];
                dp[u][0] %= mod;
            }
        }
        
        if(k == 0) {
            dp[u][0] *= 2;
            dp[u][0] %= mod;
        }
        
        if(d[u] < k)  {
            dp[u][0]++;
            dp[u][0] %= mod;
        }
        
        for(int i = 1; i < k; i++) {
            dp[u][i] = (dp[u][i] - dp[u][i + 1] + mod) % mod;
        }
                
    };
    
    dfs(0);
    
    int ans = 0;
    for(int i = 0; i <= k; i++) {
        ans = (ans + dp[0][i]) % mod;
    }
    
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}