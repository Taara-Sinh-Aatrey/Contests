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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 1 << 3;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

void solve() {
    int l, r;
    l = rand(0, N - 1);
    r = rand(l, N - 1);
    // scan(l, r);
    int n = r - l + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = l + i;
    }
    int xx = rand(0, N - 1);
    for (auto &x : a) {
        x ^= xx;
    }
    // scan(a);
    const int lg = 17;
    int ans = 0;
    for (int b = lg - 1; b >= 0; b--) {
        int should = 0, actual = 0;
        for (auto &x : a) {
            actual += x >> b & 1;
        }
        for (int x = l; x <= r; x++) {
            should += x >> b & 1;
        }
        if (actual != should) {
            assert(actual + should == n);
            ans |= 1 << b;
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i] ^ ans;
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (b[i] != l + i) {
            dbg("counter testcase");
            print(1);
            print(l, r);
            print(a);
            dbg(xx, ans);
            exit(0);
        }
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 10000;
    // scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}