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
    string s;
    scan(n, s);
    const int m = 32;
    vector<bool> dp(m);
    dp[0] = true;
    auto check = [&] (int len, int mask, char ch) {
        string st;
        for (int i = len - 1; i >= 0; i--) {
            st += char('0' + (mask >> i & 1));
        }
        st += ch;
        int sz = st.size();
        for (int i = 0; i < sz / 2; i++) {
            if (st[i] != st[sz - 1 - i]) {
                return true;
            }
        }
        return false;
    };
    auto add_bit = [&] (int mask, char ch) {
        mask = mask & 15;
        mask = mask * 2 + (ch - '0');
        return mask;
    };
    for (int i = 0; i < n; i++) {
        vector<bool> ndp(m);
        for (int mask = 0; mask < m; mask++) {
            for (char ch = '0'; ch <= '1'; ch++) {
                if (ch == s[i] || s[i] == '?') {
                    if (dp[mask] && (i < 4 || check(4, mask, ch)) && (i < 5 || check(5, mask, ch)))
                        ndp[add_bit(mask, ch)] = true;
                }
            }
        }
        swap(dp, ndp);
    }
    bool ok = false;
    for (int mask = 0; mask < m; mask++) {
        ok = ok | dp[mask];
    }
    print(ok ? "POSSIBLE" : "IMPOSSIBLE");
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