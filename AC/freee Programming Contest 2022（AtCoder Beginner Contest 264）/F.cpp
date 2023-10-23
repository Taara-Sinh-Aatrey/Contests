#include "bits/stdc++.h"
#include <algorithm>
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
    int h, w;
    cin >> h >> w;
    vector<int> R(h), C(w);
    cin >> R >> C;
    vector<string> a(h);
    cin >> a;
    int ans = inf;
    for (char clr = '0'; clr <= '1'; clr++) {
        vector<vector<vector<int>>> dp(h + 1, vector<vector<int>>(w + 1, vector<int>(4, inf)));
        dp[0][1][0] = 0;
        dp[0][1][2] = C[0];
        dp[1][0][0] = 0;
        dp[1][0][1] = R[0];
        for (int r = 1; r <= h; r++) {
            for (int c = 1; c <= w; c++) {
                for (int mask = 0; mask < 4; mask++) {
                    {
                        // (r - 1, c) -> (r, c)
                        int cnt = (mask >> 1 & 1) + (a[r - 1][c - 1] != clr);
                        int new_mask = ((mask >> 1 & 1) << 1) + (cnt & 1);
                        amin(dp[r][c][new_mask], dp[r - 1][c][mask] + (cnt & 1) * R[r - 1]);
                    }
                    {
                        // (r, c - 1) -> (r, c)
                        int cnt = (mask & 1) + (a[r - 1][c - 1] != clr);
                        int new_mask = (mask & 1) + ((cnt & 1) << 1);
                        amin(dp[r][c][new_mask], dp[r][c - 1][mask] + (cnt & 1) * C[c - 1]);
                    }
                }
            }
        }
        amin(ans, *min_element(dp[h][w].begin(), dp[h][w].end()));
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}