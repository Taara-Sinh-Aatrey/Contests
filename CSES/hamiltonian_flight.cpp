/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.05.2021 11:59:45
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
    }

    vector<vector<int>> dp(1 << n, vector<int>(n));
    dp[1][0] = 1;

    for(int mask = 1; mask < 1 << n; mask++) {
        for(int u = 0; u < n; u++) {
            if(dp[mask][u] == 0 || (mask >> (n-1) & 1)) continue;
            for(int v: g[u]) {
                if((mask >> v & 1)) continue;
                int new_mask= mask | (1 << v);
                dp[new_mask][v] += dp[mask][u];
                if(dp[new_mask][v] >= mod) {
                    dp[new_mask][v] -= mod;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}