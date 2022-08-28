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
    int n, m;
    scan(n, m);
    vector<int> a(m);
    scan(a);
    sort(a.begin(), a.end());
    multiset<pair<int, int>> ms;
    for (int i = 0; i + 1 < m; i++) {
        int diff = a[i + 1] - a[i] - 1;
        ms.emplace(0, diff);
    }
    int diff = a[0] - 1 + n + 1 - a.back() - 1;
    ms.emplace(0, diff);
    int infected = m;
    int days = 0;
    while (!ms.empty()) {
        auto it = prev(ms.end());
        auto [y, x] = *it;
        ms.erase(it);
        int contri = min(days, x);
        infected += contri;
        bool can_save = days * 2 < x;
        x -= days + can_save;
        if (y == 0 && x > 0) {
            ms.emplace(1, x);
        }
        days++;
    }
    print(infected);
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

// 0
// 1

// 2
// 3

// 4
// 4

// 6
// 3