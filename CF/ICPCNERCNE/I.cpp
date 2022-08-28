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
    auto query = [&] (int r, int c) {
        cout << "SCAN " << r << " " << c << endl;
        int sum;
        cin >> sum;
        return sum;
    };
    
    auto dig = [&] (int r, int c) {
        cout << "DIG " << r << " " << c << endl;
        int sum;
        cin >> sum;
        return sum;
    };
    
    // x1 + x2 + z - 4 = a
    int a = query(1, 1) + 4;
    
    // n - x1 + n - x2 + z - 2
    // 2 * n - x1 - x2 + z - 2
    int b = query(n, 1) + 2;
    
    int z = (a + b - 2 * n) / 2;

    int s1 = a - z;
    
    // if both points lie between a and c
    // half - x1 + half - x2 + z - 2
    // x1 - x2 + z = c
    int half = s1 / 2;
    int c = query(half, 1) + 2;
    int d1 = c - z;
    dbg(z, s1, d1);
    
    int x1 = (s1 + d1) / 2;
    int x2 = s1 - x1;
    
    s1 = z;
    half = s1 / 2;
    // s1 - 2 + y1 - y2 = d
    int d = query(1, half) + 2;
    d1 = d - (x1 + x2);
    int y1 = (s1 + d1) / 2, y2 = s1 - y1;
    
    // check opposite side
    // n / 2 - x1 + x2 - n / 2 + z
    // x2 - x1 + z
    
    if (dig(x1, y1) == 0) {
        dig(x1, y2);
        dig(x2, y1);
    }
    else {
        dig(x2, y2);
    }
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