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
    vector<pair<int, int>> a(3);
    scan(a);
    for (int i = 0; i < 3; i++) {
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }
    int ans = inf;
    bool ok = false;
    auto consider = [&] (int l, int r, int L, int R) {
        if (l == L && l == r + R)
            ok = true;
        if (r == R && l + L == r)
            ok = true;
        swap(l, r);
        if (l == L && l == r + R)
            ok = true;
        if (r == R && l + L == r)
            ok = true;
    };
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            int k = 0 + 1 + 2 - i - j;
            if (a[i].second == a[j].second)
                consider(a[i].first + a[j].first, a[i].second, a[k].first, a[k].second);
            if (a[i].first == a[j].first)
                consider(a[i].second + a[j].second, a[i].first, a[k].first, a[k].second);
            
            swap(a[j].first, a[j].second);
            if (a[i].second == a[j].second)
                consider(a[i].first + a[j].first, a[i].second, a[k].first, a[k].second);
            if (a[i].first == a[j].first)
                consider(a[i].second + a[j].second, a[i].first, a[k].first, a[k].second);
            swap(a[j].first, a[j].second);
        }
    }
    
    if (a[0].first == a[1].first && a[1].first == a[2].first && a[0].second + a[1].second + a[2].second == a[0].first) {
        ok = true;
    }
    if (a[0].second == a[1].second && a[1].second == a[2].second && a[0].first + a[1].first + a[2].first == a[0].first) {
        ok = true;
    }
    print(ok ? "YES" : "NO");
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