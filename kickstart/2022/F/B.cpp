/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.09.2022 22:36:27
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
    for (int caseno = 1; caseno <= testcases; caseno++) {
        cout << "Case #" << caseno << ": ";
        int n, q;
        cin >> n >> q;
        vector<vector<int>> g(n);
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v, --u, --v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> lvls;
        queue<int> qu;
        qu.emplace(0);
        const int inf = 1e18L + 5;
        vector<int> dis(n, inf);
        dis[0] = 0;
        while (!qu.empty()) {
            lvls.emplace_back(qu.size());
            queue<int> nq;
            while (!qu.empty()) {
                int u = qu.front();
                qu.pop();
                for (auto& v: g[u]) {
                    if (dis[v] > dis[u] + 1) {
                        dis[v] = dis[u] + 1;
                        nq.push(v);
                    }
                }
            }
            swap(qu, nq);
        }
        int ans = 0;
        int cur = 0, filled = 0;
        while (q--) {
            int x;
            cin >> x, --x;
            filled += 1;
            if (cur < lvls.size() && filled >= lvls[cur]) {
                ans += filled;
                filled = 0;
                cur++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}