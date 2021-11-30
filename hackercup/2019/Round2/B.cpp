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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 4e3 + 5;

void solve() {
    int n, m;
    scan(n, m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        scan(x, y);
        --x, --y;
        while(x < y) {
            g[x].emplace_back(y);
            g[y].emplace_back(x);
            x++, y--;
        }
    }
    vector<vector<int>> ccs;
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        ccs.back().emplace_back(u);
        for(auto& v : g[u]) {
            if(vis[v]) continue;
            dfs(v);
        }    
    };
    for (int i = 0; i < n; i++) {
        if(vis[i]) continue;
        ccs.push_back({});
        dfs(i);
    }
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int it = 0; it < ccs.size(); it++) {
        int x = ccs[it].size();
        for (int i = n; i >= x; i--) {
            if(dp[i] != -1) continue;
            if(dp[i - x] != -1) {
                dp[i] = it;
            }
        }
    }
    int best_sz = 0;
    for (int i = 0; i <= n; i++) {
        if(dp[i] == -1) continue;
        if(abs(n - 2 * i) < abs(n - 2 * best_sz)) {
            best_sz = i;
        }
    }
    string s(n, '0');
    while(best_sz > 0) {
        auto &cc = ccs[dp[best_sz]];
        for(auto& i : cc) {
            s[i] = '1';
        }
        best_sz -= cc.size();
    }
    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}