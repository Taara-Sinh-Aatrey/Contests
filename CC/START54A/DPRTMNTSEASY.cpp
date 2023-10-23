/**
 *    author:  Taara Sinh Aatrey
 *    created: 02.09.2022 01:16:44
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
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        vector<int> degree(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v, --u, --v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            degree[u]++;
            degree[v]++;
        }
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
        }
        vector<vector<int>> which(n);
        int id = 0;
        vector<vector<int>> all_groups;
        auto in_same_group = [&] (int u, int v) {
            for (auto &uid : which[u])
                for (auto &vid : which[v])
                    if (uid == vid)
                        return true;
            return false;
        };
        auto add_group = [&] (const vector<int> &group) {
            all_groups.emplace_back(group);
            for (auto &u : group) {
                which[u].emplace_back(id);
            }
            id++;
        };
        for (int u = 0; u < n; u++) {
            vector<vector<int>> groups;
            for (auto &v : g[u]) {
                if (in_same_group(u, v))
                    continue;
                bool found = false;
                for (auto &group : groups) {
                    bool ok = true;
                    for (auto &w : group) {
                        if (!binary_search(g[w].begin(), g[w].end(), v)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        found = true;
                        group.emplace_back(v);
                    }
                }
                if (!found) {
                    groups.emplace_back();
                    groups.back().emplace_back(v);
                }
            }
            assert(groups.size() <= 2);
            for (auto &group : groups) {
                group.emplace_back(u);
                add_group(group);
            }
        }
        int mx_sz = 0;
        for (int u = 0; u < n; u++) {
            mx_sz = max<int>(mx_sz, which[u].size());
        }
        assert(mx_sz <= 2);
        if (mx_sz == 1) {
            assert(m == n * (n - 1) / 2);
            // cout << 1 << '\n';
            // for (int i = 0; i < n; i++) {
            //     cout << which[i][0] + 1 << " \n"[i == n - 1];
            // }
            // cout << 1 << '\n';
            continue;
        }
        dbg(all_groups);
        // find the center group
        int center_id = -1;
        for (int i = 0; i < all_groups.size(); i++) {
            int sz = 0;
            set<int> gs;
            for (auto &u : all_groups[i]) {
                bool found = false;
                for (auto &group_id : which[u]) {
                    if (group_id != i) {
                        found = true;
                        // sz += all_groups[group_id].size();
                        gs.emplace(group_id);
                    }
                }
                // part of only one group
                if (!found) {
                    sz++;
                }
            }
            dbg(all_groups[i]);
            for (auto &group_id : gs) {
                sz += all_groups[group_id].size();
            }
            dbg(sz);
            dbg(gs);
            if (sz == n) {
                center_id = i;
                for (auto &u : all_groups[i]) {
                    bool found = false;
                    for (auto &group_id : which[u]) {
                        if (group_id != i) {
                            found = true;
                        }
                    }
                    // part of only one group
                    if (!found) {
                        add_group({u});
                    }
                }
                break;
            }
        }
        for (auto &group : all_groups) {
            int sz = group.size();
            m -= sz * (sz - 1) / 2;
        }
        sort(all_groups[center_id].begin(), all_groups[center_id].end());
        for (int i = 0; i < all_groups.size(); i++) {
            if (i == center_id) continue;
            int cnt = 0;
            for (auto &u : all_groups[i]) {
                cnt += binary_search(all_groups[center_id].begin(), all_groups[center_id].end(), u);
            }
            assert(cnt == 1);
        }
        assert(m == 0);
        // cout << int(all_groups.size()) - 1 << '\n';
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (auto &group_id : which[i]) {
                if (group_id != center_id) {
                    cnt++;
                    // cout << group_id + 1 - (group_id > center_id) << " \n"[i == n - 1];
                }
            }
        }
        dbg(center_id);
        // for (auto &u : all_groups[center_id]) {
        //     cout << u + 1 << " ";
        // }
        // cout << '\n';
        assert(cnt == n);
    }
    return 0;
}