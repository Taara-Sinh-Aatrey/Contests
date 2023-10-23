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
    auto find_max = [&] (vector<int> &a) {
        int n = a.size();
        vector<int> pref = a;
        for (int i = 1; i < n; i++) {
            pref[i] += pref[i - 1];
        }
        pref.insert(pref.begin(), 0);
        vector<int> suff = a;
        for (int i = n - 2; i >= 0; i--) {
            suff[i] += suff[i + 1];
        }
        suff.emplace_back(0);
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                amax(dp[i + (n - j)], pref[i] + suff[j]);
            }
        }
        return dp;
    };
    int n;
    scan(n);
    vector<int> a(n);
    scan(a);
    int m;
    scan(m);
    vector<int> b(m);
    scan(b);
    vector<int> A = find_max(a);
    vector<int> B = find_max(b);
    vector<int> dp(n + m + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            amax(dp[i + j], A[i] + B[j]);
        }
    }
    int k;
    scan(k);
    print(dp[k]);
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