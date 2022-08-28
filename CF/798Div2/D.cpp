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
    int n, m;
    scan(n, m);
    vector<string> s(n + 2, string(m + 2, '?'));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scan(s[i][j]);
        }
    }
    vector<vector<int>> TR(n + 2, vector<int>(m + 2, -inf)), RB(n + 2, vector<int>(m + 2, -inf)), BL(n + 2, vector<int>(m + 2, -inf)), LT(n + 2, vector<int>(m + 2, -inf));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'B') {
                TR[i][j] = RB[i][j] = BL[i][j] = LT[i][j] = 0;
            }
            amax(LT[i][j], max(LT[i - 1][j], LT[i][j - 1]) + 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            amax(TR[i][j], max(TR[i - 1][j], TR[i][j + 1]) + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            amax(BL[i][j], max(BL[i + 1][j], BL[i][j - 1]) + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            amax(RB[i][j], max(RB[i + 1][j], RB[i][j + 1]) + 1);
        }
    }
    array<int, 3> ans{inf, -1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            amin(ans, array<int, 3>{max<int>({0, TR[i][j], RB[i][j], BL[i][j], LT[i][j]}), i, j});
        }
    }
    print(ans[1], ans[2]);
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