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
    vector<int> a(n), b(n);
    scan(a, b);
    vector<int> cost(16, inf);
    for (int i = 0; i < n; i++) {
        amin(cost[1], abs(a[0] - b[i]));
        amin(cost[2], abs(a[n - 1] - b[i]));
        amin(cost[4], abs(b[0] - a[i]));
        amin(cost[8], abs(b[n - 1] - a[i]));
    }
    cost[1 + 4] = abs(a[0] - b[0]);
    cost[1 + 8] = abs(a[0] - b[n - 1]);
    cost[2 + 4] = abs(a[n - 1] - b[0]);
    cost[2 + 8] = abs(a[n - 1] - b[n - 1]);
    for (int mask = 0; mask < 1 << 4; mask++) {
        for (int mask2 = 0; mask2 < 1 << 4; mask2++) {
            amin(cost[mask], cost[mask2] + cost[mask & ~mask2]);
        }
    }
    print(cost[15]);
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