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
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (n - 2) * a[i] * a[i];
        ans += (n - 2) * b[i] * b[i];
    }
    int tsm = accumulate(a.begin(), a.end(), 0LL);
    tsm += accumulate(b.begin(), b.end(), 0LL);
    vector<bool> dp(tsm + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++) {
        vector<bool> ndp(tsm + 1, false);
        for (int j = tsm; j >= 0; --j) {
            if (dp[j]) {
                if (j + a[i] < tsm)
                    ndp[j + a[i]] = 1;
                if (j + b[i] < tsm)
                    ndp[j + b[i]] = 1;
            }
        }
        swap(dp, ndp);
    }
    int mini = 1e8, sm = -1;
    for (int i = 0; i < tsm; i++) {
        if (dp[i]) {
            int diff = abs(i - (tsm - i));
            if (diff < mini) {
                mini = diff;
                sm = i;
            }
        }
    }
    ans += (sm * sm);
    sm = tsm - sm;
    ans += sm * sm;
    cout << ans << '\n';
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