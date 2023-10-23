#include<bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v, --u, --v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    vector<int> l(n);
    vector<vector<vector<pair<bool, int>>>> dp(n);
    vector<int> sz(n, 1);
    function<void(int, int)> dfs = [&] (int u, int par) {
      for(auto& v : g[u]) {
        if(v == par) 
          continue;
        dfs(v, u);
        sz[u] += sz[v];
      }
      dp[u].resize(g[u].size() + 1, vector<pair<bool, int>>(sz[u] + 1, pair(false, 0)));
      dp[u][0][a[u]] = {true, a[u]};
      int so_far = 1;
      int pv = 0;
      for(int i = 0; i < int(g[u].size()); i++) {
        int v = g[u][i];
        if(v == par) 
          continue;
        l[u] = i + 1;
        for (int x = 0; x <= so_far; x++) {
          for (int y = 0; y <= sz[v]; y++) {
            if (dp[u][pv][x].first && dp[v][l[v]][y].first && !dp[u][i + 1][x + y].first) {
              dp[u][i + 1][x + y] = {true, y};
            }
          }
        }
        pv = i + 1;
        so_far += sz[v];
      }
      for (int i = 0; i <= sz[u]; i++) {
        if (dp[u][l[u]][i].first && !dp[u][l[u]][sz[u] - i].first) {
          dp[u][l[u]][sz[u] - i] = {true, -1};
        }
      }
    };
    dfs(0, -1);
    vector<int> ans;
    function<void(int, int, int)> dfs2 = [&] (int u, int par, int target) {
      assert(dp[u][l[u]][target].first);
      if (dp[u][l[u]][target].second == -1) {
        ans.emplace_back(u + 1);
        target = sz[u] - target;
      }
      for(int i = int(g[u].size()) - 1; i >= 0; i--) {
        int v = g[u][i];
        if(v == par)
          continue;
        assert(dp[u][i + 1][target].first);
        int taken = dp[u][i + 1][target].second;
        dfs2(v, u, taken);
        target -= taken;
      }
      assert(dp[u][0][target].first);
    };
    dfs2(0, -1, n / 2);
    cout << ans.size() << '\n';
    for (int &x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
  return 0;
}