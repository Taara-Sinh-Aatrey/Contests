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
const int inf = 1e18L + 5, N = 2e5 + 5;
int mod = 1;

int inverse(int a, int m) {
    if(a == 0) return 0;
    int MOD = m;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    u %= MOD;
    if(u < 0) u += MOD;
    return u;
}

int Pow(int a, int b, int P = mod) {
    if (b < 0)
        return inverse(Pow(a, -b, P), P);
    int res = 1;
    while(b > 0) {
        if(b & 1) 
            res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void solve() {
    int a, b, x;
    scan(a, b, x);
    for (int t = 0; t < x; t++) {
        mod *= 10;
    }
    int last = Pow(a, b, mod);
    double t = b * log10(double(a));
    t = t - int(t);
    t = pow(10, t);
    int first = t * pow(10, x - 1);
    auto Print = [&] (int num) {
        cout << (string(x - to_string(num).size(), '0')) << num << " ";
    };
    Print(first);
    Print(last);
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