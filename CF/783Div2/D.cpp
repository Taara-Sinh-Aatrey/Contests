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
    vector<int> a(n);
    scan(a);
    vector<int> pref = a;
    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }
    vector<int> mx_suff = pref;
    for (int i = n - 2; i >= 0; i--) {
        amax(mx_suff[i], mx_suff[i + 1]);
    }
    int cur = -1;
    int sum = 0;
    vector<int> dp(n, -inf);
    for (int i = 0; i < n; i++) {
        amax(dp[i], cur);
        {
            int lo = i, hi = n - 1;
            int md = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (mx_suff[mid] > sum) {
                    md = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            if (md != -1) {
                amax(dp[md], (i == 0 ? 0 : dp[i - 1]) + md - i + 1);
            }
        }
        {
            int lo = i, hi = n - 1;
            int md = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (mx_suff[mid] >= sum) {
                    md = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            if (md != -1) {
                amax(dp[md], (i == 0 ? 0 : dp[i - 1]));
            }
        }
        amax(cur, dp[i]);
        cur--;
        sum += a[i];
    }
    print(dp[n - 1]);
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