/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2022 18:14:06
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto check = [&] (int max_ops) {
        queue<int> q;
        vector<int> sum(n);
        vector<bool> mark(n, false);
        for (int u = 0; u < n; u++) {
            for (auto &v : g[u]) {
                sum[u] += a[v];
            }
            if (sum[u] <= max_ops) {
                q.emplace(u);
                mark[u] = true;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : g[u]) {
                sum[v] -= a[u];
                if (sum[v] <= max_ops && !mark[v]) {
                    mark[v] = true;
                    q.emplace(v);
                }
            }
        }
        return count(mark.begin(), mark.end(), true) == n;
    };
    int low = 0, high = 2e14;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low;
    return 0;
}