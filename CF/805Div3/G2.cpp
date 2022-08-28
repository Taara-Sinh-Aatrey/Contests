#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    scan(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scan(u, v), --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    const int lvl = 19;
    
    vector<vector<int>> p(lvl, vector<int>(n, -1));
    vector<int> depth(n, 0);
    
    function<void(int, int)> dfs = [&](int u, int par) {
        p[0][u] = par;
        depth[u] = par == -1 ? 0 : depth[par] + 1;
        
        for(auto& v : g[u]) {
            if(v == par) continue;
            dfs(v, u);
        }    
    };
    dfs(0, -1);
    

    for(int i = 1; i < lvl; i++){
        for(int node = 0; node < n; node++){
            if(p[i - 1][node] != -1){
                p[i][node] = p[i - 1][p[i - 1][node]];
            }
        }
    }
    
    auto get = [&](int node, int dis) {
        for (int i = lvl - 1; i >= 0; i--)
            if (dis >> i & 1) 
                node = p[i][node];
        return node;
    };
    
    auto is_ancestor = [&] (int u, int par) {
        if (depth[u] < depth[par]) {
            return false;
        }
        return get(u, depth[u] - depth[par]) == par;    
    };
    
    auto is_strict_ancestor = [&] (int u, int par) {
        if (depth[u] <= depth[par]) {
            return false;
        }
        return get(u, depth[u] - depth[par]) == par;    
    };
    
    auto on_segment = [&] (int u, int par, int w) {
        return is_ancestor(u, w) && !is_strict_ancestor(par, w);
    };
    
    auto find_lca = [&](int u, int v) {
        if (depth[u] > depth[v]) { 
            swap(u, v);
        }

        v = get(v, depth[v] - depth[u]);

        if (u == v) 
            return u;

        for (int i = lvl - 1; i >= 0; i--){
            if (p[i][u] != p[i][v]){
                u = p[i][u];
                v = p[i][v];
            }
        }
        return p[0][u];
    };
    
    int q;
    scan(q);
    while (q--) {
        int m;
        scan(m);
        vector<int> a(m);
        scan(a);
        if (m == 1) {
            print("YES");
            continue;
        }
        for (auto &x : a) {
            --x;
        }
        sort(a.begin(), a.end(), [&] (int x, int y) {
            return depth[x] > depth[y];
        });
        int u = a[0], v = a[1], lca = find_lca(u, v);
        bool found = lca != u && lca != v;
        bool ok = true;
        for (int i = 2; i < m; i++) {
            int w = a[i];
            if (!found) {
                v = a[i];
                lca = find_lca(u, v);
                found = lca != u && lca != v;
            }
            else if (!on_segment(u, lca, w) && !on_segment(v, lca, w)) {
                ok = false;
                break;
            }
        }
        print(ok ? "YES" : "NO");
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}