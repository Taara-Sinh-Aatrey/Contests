#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v, --u, --v;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    int root = 0;
    int nodes = n;
    vector<bool> removed(n);
    while (true) {
      int best = -1;
      int D = -1;
      vector<int> p(n, -1), sz(n, 1), beg(n, -1), end(n, -1);
      function<void(int)> find_best = [&](int u) {
        int mx = 0;
        for(auto& v : g[u]) {
          if(v == p[u] || removed[v]) continue;
          p[v] = u;
          find_best(v);
          sz[u] += sz[v];
          mx = max(mx, sz[v]);
        }
        mx = max(mx, nodes - sz[u]);
        if (best == -1 || mx < D) {
          best = u;
          D = mx;
        }
      };
      p[root] = -1;
      find_best(root);
      int tm = 0;
      function<void(int)> dfs = [&](int u) {
        beg[u] = tm++;
        for(auto& v : g[u]) {
          if(v == p[u] || removed[v]) continue;
          p[v] = u;
          dfs(v);
          sz[u] += sz[v];
        }
        end[u] = tm;
      };
      tm = 0;
      p[best] = -1;
      dfs(best);
      cout << "? " << best+1 << endl;
      int nroot;
      cin >> nroot;
      if(nroot == -1) {
        cout << "! " << best+1 << endl;
        break;
      }
      --nroot;
      root = nroot;
      for (int i = 0; i < n; i++) {
        if (removed[i]) continue;
        if (beg[i] > end[root] || beg[i] < beg[root]) {
          removed[i] = true;
          nodes--;
        }
      }
      if (nodes == 1) {
        cout << "! " << root+1 << endl;
        break;
      }
    }
  }
}