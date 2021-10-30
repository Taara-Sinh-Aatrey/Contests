#include "bits/stdc++.h"
#include <iomanip>
#include <numeric>
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    scan(n);
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scan(a[i], b[i]);
    }
    double lo = 0, hi = accumulate(a.begin(), a.end(), 0LL);
    double ans = 0;
    for (int rep = 0; rep < 80; rep++) {
        double mid = (lo + hi) / 2;
        double l = 0, have = mid;
        for (int i = 0; i < n; i++) {
            if (have >= a[i] / b[i]) {
                have -= a[i] / b[i];
                l += a[i];
            }
            else {
                l += have * b[i];
                break;
            }
        }
        double r = accumulate(a.begin(), a.end(), 0.0); 
        have = mid;
        for (int i = n - 1; i >= 0; i--) {
            if (have >= a[i] / b[i]) {
                have -= a[i] / b[i];
                r -= a[i];
            }
            else {
                r -= have * b[i];
                break;
            }
        }
        if (l <= r) {
            ans = max(ans, l);
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(10);
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}