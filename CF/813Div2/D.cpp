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
    int n, k;
    scan(n, k);
    vector<int> a(n);
    scan(a);
    vector<int> orig = a;
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (auto &x, auto &y) {
        return a[x] < a[y];
    });
    for (int it = 0; it < k - 1; it++) {
        a[ord[it]] = 1e9;
    }
    int mn2 = *min_element(a.begin(), a.end());
    int sp = ord[k - 1];
    a[sp] = 1e9;
    int mn = *min_element(a.begin(), a.end());
    int ans = 0;
    int ans2 = 0;
    for (int i = 0; i + 1 < n; i++) {
        int cur = min(a[i], a[i + 1]);
        amax(ans, min(cur, 2 * mn));
        a[sp] = orig[sp];
        int cur2 = max(a[i], a[i + 1]);
        amax(ans2, min(cur2, mn2 * 2));
        a[sp] = 1e9;
    }
    print(max(ans, ans2));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1e5;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}