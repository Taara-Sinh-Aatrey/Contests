#include "bits/stdc++.h"
using namespace std;

int main() {
#define int int64_t
    int n, r;
    cin >> n >> r, --r;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    vector<int> p(n), d(n);
    function<void(int, int)> find_parent = [&] (int u, int par) {
        p[u] = par;
        d[u] = par == -1 ? 1 : d[par] + 1;
        for (auto& v : g[u]) {
            if (v == par) 
                continue;
            find_parent(v, u);
        }
    };
    find_parent(0, -1);
    int cur = r;
    for (int i = 0; i < d[r] / 2; i++) {
        a[cur] = 0;
        cur = p[cur];
    }
    if (d[r] % 2 == 1) {
        a[cur] /= 2;
    }
    vector<int> pref;
    function<void(int, int)> dfs = [&] (int u, int par) {
        int prev = pref.empty() ? 0 : pref.back();
        pref.emplace_back(prev + a[u]);
        ans = max(ans, pref.back());
        for (auto& v : g[u]) {
            if (v == par) 
                continue;
            dfs(v, u);
        }
        pref.pop_back();
    };
    dfs(0, -1);
    cout << ans << '\n';
    return 0;
#undef int
}