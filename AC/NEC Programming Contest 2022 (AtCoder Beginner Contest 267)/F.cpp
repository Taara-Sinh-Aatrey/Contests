/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2022 18:30:37
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

// #define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int q;
    cin >> q;
    vector<vector<array<int, 2>>> Q(n);
    vector<vector<array<int, 3>>> delayed_Q(n);
    vector<int> answer(q, -2);
    for (int i = 0; i < q; i++) {
        int node, distance;
        cin >> node >> distance, --node;
        Q[node].push_back({distance, i});
    }
    array<vector<int>, 2> childs[n];
    array<int, 2> childs_depth[n];
    vector<int> st(n), et(n);
    int timer = 0;
    const int inf = 1e9 + 5;
    vector<pair<int, int>> best_parent(n, pair(-inf, -1));
    vector<int> depth(n);
    function<void(int, int)> find_childs_size = [&] (int u, int par) -> void {
        depth[u] = par == -1 ? 0 : depth[par] + 1;
        childs_depth[u] = {0, 0};
        for (auto& v : g[u]) {
            if (v == par) continue;
            find_childs_size(v, u);
            if (childs_depth[v][0] + 1 > childs_depth[u][0]) {
                childs_depth[u][1] = childs_depth[u][0];
                childs_depth[u][0] = childs_depth[v][0] + 1;
            }
            else if (childs_depth[v][0] + 1 > childs_depth[u][1]) {
                childs_depth[u][1] = childs_depth[v][0] + 1;
            }
        }
    };
    find_childs_size(0, -1);
    vector<int> pars;
    function<void(int, int)> dfs = [&] (int u, int par) -> void {
        depth[u] = par == -1 ? 0 : depth[par] + 1;
        pars.emplace_back(u);
        st[u] = timer++;
        childs[u][0] = {u};
        for (auto &v : g[u]) {
            if (v == par) continue;
            int best_depth = (childs_depth[u][0] != childs_depth[v][0] + 1 ? childs_depth[u][0]: childs_depth[u][1]);
            best_parent[v] = pair(best_parent[u].first + 1, best_parent[u].second);
            if (best_depth + 1 > best_parent[v].first) {
                best_parent[v] = {best_depth + 1, u};
            }
        }
        for (auto& v : g[u]) {
            if (v == par) continue;
            dfs(v, u);
            childs[v][0].emplace_back(u);
            if (childs[v][0].size() > childs[u][0].size()) {
                swap(childs[u][0], childs[u][1]);
                swap(childs[u][0], childs[v][0]);
            }
            else if (childs[v][0].size() > childs[u][1].size()) {
                swap(childs[u][1], childs[v][0]);
            }
            childs[v][0] = {};
        }
        // process queries
        for (auto &[distance, idx] : Q[u]) {
            if (distance <= int(pars.size()) - 1) {
                answer[idx] = pars[int(pars.size()) - 1 - distance];
                continue;
            }
            auto &children = childs[u][0];
            int sz = children.size();
            if (distance > sz - 1) {
                if (best_parent[u].second != -1) {
                    delayed_Q[best_parent[u].second].push_back({distance - (depth[u] - depth[best_parent[u].second]), u, idx});
                }
            }
            else {
                answer[idx] = children[sz - 1 - distance];
            }
        } 
        // process queries of children
        for (auto &[distance, node, idx] : delayed_Q[u]) {
            for (auto &children : childs[u]) {
                if (distance == 0) {
                    answer[idx] = u;
                    break;
                }
                int sz = children.size();
                if (distance > sz - 1) {
                    break;
                }
                int v = children[sz - 2];
                if (st[v] <= st[node] && et[node] <= et[v]) continue;
                answer[idx] = children[sz - 1 - distance];
                break;
            }
        } 
        childs[u][1] = vector<int>();
        et[u] = timer++;
        pars.pop_back();
    };
    dfs(0, -1);
    for (auto &ans : answer) cout << ans + 1 << '\n';
    return 0;
}