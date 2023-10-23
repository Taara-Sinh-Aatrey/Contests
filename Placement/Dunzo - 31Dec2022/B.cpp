/**
 *    author:  Taara Sinh Aatrey
 *    created: 31.12.2022 11:55:58
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

long solve(int n, vector<int> from, vector<int> to, vector<int> wt) {
    vector<vector<pair<int, int>>> g(n);
    int m = from.size();
    for (int i = 0; i < m; i++) {
        from[i]--, to[i]--, wt[i]--;
        g[from[i]].emplace_back(to[i], wt[i]);
        g[to[i]].emplace_back(from[i], wt[i]);
    }
    vector<int> p(n), d(n);
    int mask = 0;
    map<int, int> cnt;
    int ans = 0;
    vector<map<int, int>> all(n);
    function<void(int, int)> dfs = [&] (int u, int par) {
        int cur = cnt[mask];
        cnt[mask]++;
        for (int i = 0; i < 26; i++) {
            cur += cnt[mask ^ (1 << i)];
        }
        ans += cur;
        map<int, int> &me = all[u];
        for (auto& [v, w] : g[u]) {
            if (v == par) 
                continue;
            mask ^= 1 << w;
            dfs(v, u);
            mask ^= 1 << w;
            map<int, int> &he = all[v];
            if (me.size() < he.size()) {
                swap(me, he);
            }
            cur = 0;
            for (auto &[msk, c] : he) {
                auto it = me.find(msk);
                if (it != me.end())
                    cur += c * it->second;
                for (int i = 0; i < 26; i++) {
                    it = me.find(msk ^ (1 << i));
                    if (it != me.end())
                        cur += c * it->second;
                }
            }
            ans += cur;
            for (auto &[msk, c] : he) {
                me[msk] += c;
            }
        }
        me[mask]++;
        cnt[mask]--;
    };
    dfs(0, -1);
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << solve(5, {1, 2, 3, 3}, {2, 3, 4, 5}, {2, 1, 1, 1}) << endl;
    cout << solve(5, {1, 1, 2, 2}, {2, 3, 4, 5}, {1, 2, 1, 2}) << endl;
    return 0;
}