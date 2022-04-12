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
    int n, t;
    scan(n, t);
    vector<int> a(n);
    scan(a);
    sort(a.begin(), a.end());
    pair<int, int> mn{inf, inf};
    for (int i = 0; i < n; i++) {
        amin(mn, pair(a[i] - (i == 0 ? 0 : a[i - 1]) - 1, i));
    }
    int ret = 0;
    for (auto i : {mn.second - 1, mn.second}) {
        if (i < 0)
            continue;
        auto b = a;
        a.erase(a.begin() + i);
        n = a.size();
        pair<int, int> mx{2 * (t - a.back() - 1) + 1, n - 1};
        for (int i = 0; i < n; i++) {
            amax(mx, pair(a[i] - (i == 0 ? 0 : a[i - 1]) - 1, i));
        }
        int ans = (mx.first - 1) / 2;
        for (int i = 0; i < n; i++) {
            amin(ans, a[i] - (i == 0 ? 0 : a[i - 1]) - 1);
        }
        amax(ret, ans);
        a = b;
    }
    print(ret);
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