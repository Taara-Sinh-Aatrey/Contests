/**
 *    author:  Taara Sinh Aatrey
 *    created: 30.08.2022 13:52:38
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++) {
        cout << "Case #" << tt << ":";
        int n, m, q;
        cin >> n >> m >> q;
        vector<vector<pair<int, int>>> g(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w, --u, --v;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        for (int i = 0; i < n; i++)
            sort(g[i].begin(), g[i].end());
        map<pair<int, int>, int> save;
        while (q--) {
            int u, v;
            cin >> u >> v, --u, --v;
            if (save.count({u, v})) {
                cout << ' ' << save[{u, v}];
            }
            if (g[u].size() > g[v].size())
                swap(u, v);
            int ans = 0;
            for (auto &[t, w] : g[u]) {
                if (t == v) {
                    ans += 2 * w;
                    continue;
                }
                auto it = lower_bound(g[v].begin(), g[v].end(), pair(t, 0LL));
                if (it != g[v].end() && it->first == t) {
                    ans += min(w, it->second);
                }
            }
            cout << ' ' << (save[{u, v}] = save[{v, u}] = ans);
        }
        cout << '\n';
    }
    return 0;
}