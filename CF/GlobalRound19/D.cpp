#include "bits/stdc++.h"
#include <numeric>
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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 1e4 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    int sum = accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL);
    vector<bool> dp(N);
    dp[0] = true;
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += a[i] * a[i];
        cost += b[i] * b[i];
        for (int j = N - 1; j >= 0; j--) {
            if (dp[j] && j + a[i] < N)
                dp[j + a[i]] = true;
            if (dp[j] && j + b[i] < N)
                dp[j + b[i]] = true;
        }
    }
    cost *= n - 2;
    int a_sum = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] && abs(2 * i - sum) < abs(2 * a_sum - sum))
            a_sum = i;
    }
    int b_sum = sum - a_sum;
    cost += a_sum * a_sum + b_sum * b_sum;
    print(cost);
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