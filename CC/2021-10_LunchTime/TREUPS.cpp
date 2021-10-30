#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v, --u, --v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    vector<int> c(n);
    int spare = 0;
    int depth = 0;
    vector<int> childs;
    function<void(int, int)> dfs = [&](int u, int par) {
      bool leaf = true;
      if (depth == 0) {
        int nChild = g[u].size() - (par != -1);
        childs.emplace_back(abs(nChild - 1));
      }
      for(auto& v : g[u]) {
        if(v == par) continue;
        depth ^= 1;
        dfs(v, u);
        depth ^= 1;
      }
    };
    dfs(0, -1);
    int tot = accumulate(childs.begin(), childs.end(), 0);
    if (q == 1) {
      cout << tot << '\n';
    }
    else {
      const int N = 1e5 + 1;
      bitset<N> bs;
      bs[0] = true;
      for (auto &child : childs) {
        bs |= bs << child;
      }
      int ans = n + 1;
      for (int i = 0; i <= tot; i++) {
        if (bs[i])
          ans = min(ans, abs(2 * i - tot));
      }
      cout << ans << '\n';
    }
  }
  return 0;
}