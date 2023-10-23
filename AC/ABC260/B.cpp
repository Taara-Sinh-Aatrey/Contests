#include "bits/stdc++.h"
#include <cstdio>
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
    int n, x, y, z;
    scan(n, x, y, z);
    vector<array<int, 3>> score(n);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            scan(score[j][i]);
            score[j][2] = j;
        }
    }
    sort(score.begin(), score.end(), [&] (auto &a, auto &b) {
        return make_tuple(a[0], -a[2]) > make_tuple(b[0], -b[2]);
    });
    sort(score.begin() + x, score.end(), [&] (auto &a, auto &b) {
        return make_tuple(a[1], -a[2]) > make_tuple(b[1], -b[2]);
    });
    sort(score.begin() + x + y, score.end(), [&] (auto &a, auto &b) {
        return make_tuple(a[0] + a[1], -a[2]) > make_tuple(b[0] + b[1], -b[2]);
    });
    score.resize(x + y + z);
    vector<int> ans;
    for (auto &[math, english, roll] : score) {
        ans.emplace_back(roll + 1);
    }
    sort(ans.begin(), ans.end());
    for (auto &x : ans) {
        print(x);
    }
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