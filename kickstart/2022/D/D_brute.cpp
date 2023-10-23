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
    int n, m, k;
    scan(n, m, k);
    vector<int> freq(n);
    vector<int> g[n];
    vector<bool> innocent(n, false);
    vector<bool> vis(n, false);
    queue<int> q;
    for (int i = 0; i < m; i++) {
        int a, b;
        scan(a, b);
        --a, --b;
        g[a].emplace_back(b);
    }
    function<void(int, int)> dfs = [&] (int u, int d) {
        vis[u] = true;
        if (d > k) {
            innocent[u] = true;
        }
        for(auto& v : g[u]) {
            if (!vis[v]) {
                dfs(v, d + 1);
            }
            else if (innocent[u] && !innocent[v]) {
                dfs(v, k + 1);
            }
        }    
    };
    for (int u = 0; u < n; u++) {
        if (!vis[u]) {
            dfs(u, 1);
        }
    }
    print(count(innocent.begin(), innocent.end(), true));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}