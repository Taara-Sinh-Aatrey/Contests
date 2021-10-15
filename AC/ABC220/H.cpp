/*
correct for acyclic graph
To learn: 
    Meet in the middle
    Fast Hadamard Transform
*/
#include "bits/stdc++.h"
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<bool> vis(n);
    vector<array<int, 4>> dp(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        dp[u] = {1, 0, 1, 0};
        for(auto& v : g[u]) {
            if(vis[v]) continue;
            dfs(v);
            array<int, 4> res = {0, 0, 0, 0};
            for (int m1 = 0; m1 < 4; m1++) {
                for(int m2 = 0; m2 < 4; m2++) {
                        res[((m1 >> 0 & 1) ^ (m2 >> 0 & 1) ^ (m1 >> 1 & 1 || m2 >> 1 & 1)) + (m1 & 2)] += dp[u][m1] * dp[v][m2]; 
                }
            }
            swap(res, dp[u]);
        }
    };
    array<int, 2> ans = {1, 0};
    for (int u = 0; u < n; u++) {
        if(vis[u]) continue;
        dfs(u);
        array<int, 2> nans = {0, 0};
        for (int m1 = 0; m1 < 2; m1++) {
            for(int m2 = 0; m2 < 4; m2++) {
                nans[(m1 >> 0 & 1) ^ (m2 >> 0 & 1)] += ans[m1] * dp[u][m2];
            }
        }
        swap(ans, nans);
    }
    print(ans[0]);
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