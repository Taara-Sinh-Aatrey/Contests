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
const int inf = 1e18L + 5, mod = 998244353, N = 2e5 + 5;

void solve() {
    int n, m, k;
    scan(n, m, k);
    k = abs(k);
    vector<int> a(m);
    scan(a);
    for (auto& x : a) --x;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    const int lvl = 19;
    
    vector<vector<int>> p(lvl, vector<int>(n, -1));
    vector<int> depth(n, 0);
    
    map<pair<int, int>, int> cnt;
    function<void(int, int)> dfs = [&](int u, int par) {
        p[0][u] = par;
        depth[u] = par == -1 ? 0 : depth[par] + 1;
        
        for(auto& v : g[u]) {
            if(v == par) continue;
            cnt[{v, u}] = 0;
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
    
    int tot = 0;
    for (int i = 1; i < m; i++) {
        int u = a[i];
        int v = a[i - 1];
        int lca = find_lca(u, v);
        while (u != lca) {
            int par = p[0][u];
            cnt[{u, par}]++;
            u = par;
            tot++;
        }
        while (v != lca) {
            int par = p[0][v];
            cnt[{v, par}]++;
            v = par;
            tot++;
        }
    }
    
    // r + b = tot
    // r - b = k
    if (tot % 2 != k % 2 || k > tot) {
        print(0);
        return;
    }
    int r = (tot + k) / 2;
    int b = tot - r;
    if (r > b) swap(r, b);
    vector<int> dp(r + 1);
    dp[0] = 1;
    for (auto &[edge, wt] : cnt) {
        for (int i = r; i - wt >= 0; i--) {
            dp[i] += dp[i - wt];
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    cout << dp[r];
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