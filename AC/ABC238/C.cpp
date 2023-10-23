#include "bits/stdc++.h"
using namespace std;

istream& operator>>(istream& is, __int128_t &number) { bool negative = false; char c; number = 0; c = getchar(); if (c == '-') { negative = true; c = getchar(); } for (; (c >= '0' && c <= '9'); c = getchar()) number = number * 10 + (c - '0'); if (negative) number *= -1; return is; }
istream& operator>>(istream& is, __uint128_t &number) { char c; number = 0; c = getchar(); for (; (c >= '0' && c <= '9'); c = getchar()) number = number * 10 + (c - '0'); return is; }
ostream& operator<<(ostream& os, __int128_t x) {if (x < 0) { os << "-"; x *= -1; } if (x == 0) { return os << "0"; } string s; while (x) { s += char(x % 10 + '0'); x /= 10; } reverse(s.begin(), s.end()); return os << s; }
ostream& operator<<(ostream& os, __uint128_t x) {if (x == 0) { return os << "0"; } string s; while (x) { s += char(x % 10 + '0'); x /= 10; } reverse(s.begin(), s.end()); return os << s;}
void dbg_print(const __int128_t &x) { cerr << x; } void dbg_print(const __uint128_t &x) { cerr << x; }
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

#define int __int128_t
const int inf = 1e18L + 5, mod = 998244353, N = 2e5 + 5;

void solve() {
    int num;
    scan(num);
    int ans = 0;
    int lo = 1, hi = 10;
    while (num >= lo) {
        int ub = min(hi - 1, num);
        ans += (1 + ub - lo + 1) * (ub - lo + 1) / 2 % mod;
        ans %= mod;
        lo *= 10;
        hi *= 10;
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}