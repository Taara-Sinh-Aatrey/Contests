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
const int inf = 1e18L + 5, N = 2e5 + 5;

#define msb(x) (int) (63 - __builtin_clzll(x))
#define lsb(x) __builtin_ctzll(x)

void solve() {
    int n, mod;
    scan(n, mod);
    vector<int> a(n);
    scan(a);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i] % mod;
    vector<vector<int>> dp(1 << n, vector<int>(mod, -inf));
    dp[0][0] = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int k = 0; k < mod; k++) {
            int val = dp[mask][k];
            int val10 = val * 10;
            int val10mod = val * 10 % mod;
            if (val == -inf)
                continue;
            int msk = ~mask & ((1 << n) - 1);
            for (int i = msb(msk); msk > 0; i = msb(msk)) {
                int nval10mod = val10mod + b[i];
                if (nval10mod >= mod)
                    nval10mod -= mod;
                amax(dp[mask | (1 << i)][nval10mod], val10 + a[i]);
                msk ^= 1 << i;
            }
        }
    }
    int ans = 0;
    for (auto &val : dp[(1 << n) - 1]) {
        if (val != -inf) {
            ans = val;            
        }
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