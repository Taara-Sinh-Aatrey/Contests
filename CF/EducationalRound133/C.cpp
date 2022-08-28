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
    vector<vector<int>> a(2, vector<int>(n));
    scan(a);
    amin(a[0][0], -1);
    int ans = inf;
    auto b = a, c = a;
    for (int i = 0; i < 2; i++) {
        for (int j = n - 2; j >= 0; j--) {
            b[i][j] = max(a[i][j] + n - 1 - j, b[i][j + 1]);
            c[i][j] = max(a[i][j], c[i][j + 1] + 1);
        }
    }
    int p0 = -1, p1 = inf;
    for (int i = 0; i < n; i++) {
        int x = a[0][i], y = a[1][i];
        
        int cand = max(p0 + 1 + n - 1 - i, b[0][i] + 1);
        cand = max(cand + 1 + n - 1 - i, c[1][i] + 1);
        amin(ans, cand);
        
        cand = max(p1 + 1 + n - 1 - i, b[1][i] + 1);
        cand = max(cand + 1 + n - 1 - i, c[0][i] + 1);
        amin(ans, cand);
        
        int np1 = max(p0, x) + 1;
        np1 = max(np1, y) + 1;
        
        int np0 = max(p1, y) + 1;
        np0 = max(np0, x) + 1;
        
        p0 = np0;
        p1 = np1;
    }
    amin(ans, p0, p1);
    print(ans);
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


