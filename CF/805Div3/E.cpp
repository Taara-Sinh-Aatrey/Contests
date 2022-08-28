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
    int n;
    scan(n);
    vector<vector<int>> g(n);
    multiset<pair<int, int>> ms;
    for(int i = 0; i < n; i++) {
        int u, v;
        scan(u, v), --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        ms.emplace(u, v);
        ms.emplace(v, u);
    }
    vector<int> color(n, 0);
    function<bool(int)> dfs = [&] (int u) -> bool {
        for (auto& v : g[u]) {
            if (u == v) {
                return false;
            }
            if (ms.find({u, v}) == ms.end()) {
                continue;
            }
            ms.erase(ms.find({u, v}));
            ms.erase(ms.find({v, u}));
            int clr = 0;
            while (clr < 2 && (color[u] >> clr & 1 || color[v] >> clr & 1)) {
                clr++;
            }
            if (clr == 2) {
                return false;
            }
            color[u] |= 1 << clr;
            color[v] |= 1 << clr;
            if (!dfs(v)) {
                return false;
            }
        }
        return true;
    };
    bool ok = true;
    for (int u = 0; u < n; u++) {
        if (color[u] == 0) {
            ok &= dfs(u);
        }
    }
    print(ok ? "YES" : "NO");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}