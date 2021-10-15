#include "bits/stdc++.h"
#include <array>
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    scan(n);
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }
    vector<int> a(n);
    scan(a);    
    vector<int> p(n), d(n);
    vector<array<int, 2>> mxd(n);
    vector<int> ans(n);
    auto upd = [&] (array<int, 2>& x, int y) {
        if (y > x[0]) {
            x[1] = x[0];
            x[0] = y;
        }
        else if (y > x[1]) {
            x[1] = y;
        }            
    };
    function<void(int, int)> dfs_down = [&](int u, int par) {
        p[u] = par;
        mxd[u] = {-inf, -inf};
        for(auto& [w, v] : g[u]) {
            if(v == par) continue;
            dfs_down(v, u);
            upd(mxd[u], max(a[v], mxd[v][0]) + w);
        }
        ans[u] = mxd[u][0];
    };
    dfs_down(0, -1);
    vector<int> mxu(n, -inf);
    function<void(int, int)> dfs_up = [&](int u, int par) {
        for(auto& [w, v] : g[u]) {
            if(v == par) continue;
            int mx = mxd[u][0];
            if (max(a[v], mxd[v][0]) + w == mxd[u][0]) {
                mx = mxd[u][1];
            }
            mx = max({mx, mxu[u], a[u]}) + w;
            mxu[v] = mx;
            ans[v] = max(ans[v], mxu[v]);
            dfs_up(v, u);
        }
    };
    dfs_up(0, -1);
    for (auto& x : ans) print(x);
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

    return 0;
}