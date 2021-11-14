#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    auto fun = [&] (int x, vector<pair<int, int>>& a) {
        int sum = 0;
        for (auto& [lo, hi] : a) {
            if (x < lo) {
                sum += lo - x;
            }
            else if (x > hi) {
                sum += x - hi;
            }
        } 
        return sum;
    };
    int n;
    scan(n);
    vector<pair<int, int>> x(n), y(n);
    for (int i = 0; i < n; i++) {
        scan(x[i].first, y[i].first, x[i].second, y[i].second);
    }
    auto find_min = [&] (vector<pair<int, int>>& vec) {
        int lo = -1e9, hi = 1e9;
        int ans = -inf;
        int best = inf;
        while (lo <= hi) {
            int mid1 = (lo + hi) / 2;
            int v1 = fun(mid1, vec);
            if (v1 == 0) {
                if (v1 < best || (v1 == best && mid1 < ans)) {
                    ans = mid1;
                    best = v1;
                }
                hi = mid1 - 1;
                continue;
            }
            int mid2 = mid1 + 1;
            int v2 = fun(mid2, vec);
            if (v1 <= v2) {
                if (v1 < best || (v1 == best && mid1 < ans)) {
                    ans = mid1;
                    best = v1;
                }
                hi = mid1 - 1;
            }
            else {
                if (v2 < best || (v2 == best && mid2 < ans)) {
                    ans = mid2;
                    best = v2;
                }
                lo = mid2 + 1;
            }
        } 
        return ans;
    };
    int xx = find_min(x), yy = find_min(y);
    print(xx, yy);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}