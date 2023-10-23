#include "bits/stdc++.h"
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
    int c1, c2, c3, n, m;
    scan(c1, c2, c3, n, m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scan(u, v), --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    auto bfs = [&] (vector<int> src, vector<int> &bfs_dist) {
        bfs_dist.resize(n, inf);
        queue<int> q;
        for (int ele: src) {
            q.push(ele);
            bfs_dist[ele] = 0;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v: g[u]) {
                if (bfs_dist[v] > bfs_dist[u] + 1) {
                    bfs_dist[v] = bfs_dist[u] + 1;
                    q.push(v);
                }
            }
        }
    };
    vector<int> d1, d2, dn;
    bfs({0}, d1);
    bfs({1}, d2);
    bfs({n - 1}, dn);
    int ans = inf;
    for (int i = 0; i < n; i++) {
        amin(ans, d1[i] * c1 + d2[i] * c2 + dn[i] * c3);
    }
    print(ans);
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