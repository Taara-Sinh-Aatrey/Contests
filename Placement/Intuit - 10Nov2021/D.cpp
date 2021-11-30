#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i], --a[i];
    }
    vector<int> sz(n), p(n, -1);
    int i = 0;
    function<void()> dfs = [&]() {
        if (i >= n) return;
        int u = a[i];
        i++;
        sz[u]++;
        while (i < n && a[i] != p[u]) {
            int v = a[i];
            p[v] = u;
            dfs();
            sz[u] += sz[v];
        }
        assert(p[u] == -1 || a[i++] == p[u]);
    };
    dfs();
    while (sz.back() == 0) sz.pop_back();
    for (auto &x : sz) cout << x << " ";
    return 0;
} 

//     1 
//  2     3
// 4 5   6 7