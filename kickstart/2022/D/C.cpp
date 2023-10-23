#include "bits/stdc++.h"
#include <algorithm>
#include <cstdio>
#include <vector>
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
    int n;
    scan(n);
    vector<int> a(n);
    scan(a);
    int m;
    scan(m);
    vector<int> b(m);
    scan(b);
    const int M = 2501;
    vector<vector<int>> pos(M);
    for (int i = 0; i < m; i++) {
        pos[b[i]].emplace_back(i);
    }
    vector<int> dp(pos[a[0]].size(), 0);
    for (int i = 1; i < n; i++) {
        int prev = a[i - 1];
        int cur = a[i];
        auto preprocess = [&] (int beg, int end) {
            vector<int> vec;
            int x = beg, mn = inf;
            for (int j = beg; beg < end ? j <= end : j >= end; beg < end ? j++ : j--) {
                mn += abs(pos[prev][j] - x);
                amin(mn, dp[j]);
                vec.emplace_back(mn);
                x = pos[prev][j];
            }
            return vec;
        };
        auto left = preprocess(0, int(pos[prev].size()) - 1);
        auto right = preprocess(int(pos[prev].size()) - 1, 0);        
        // int x = -inf, mn = 0; 
        // for (int j = 0; j < pos[prev].size(); j++) {
        //     mn += pos[prev][j] - x;
        //     x = pos[prev][j];
        //     amin(mn, left[j]);
        //     left[j] = mn;
        // }
        // x = inf, mn = 0;
        // for (int j = int(pos[prev].size()) - 1; j >= 0; j--) {
        //     mn += x - pos[prev][j];
        //     x = pos[prev][j];
        //     amin(mn, right[j]);
        //     right[j] = mn;
        // }
        vector<int> new_dp(pos[cur].size(), inf);
        auto consider = [&] (int j, int k) {
            if (j >= 0 && j < pos[prev].size()) {
                amin(new_dp[k], dp[j] + abs(pos[cur][k] - pos[prev][j]));
            }
        };
        for (int k = 0; k < pos[cur].size(); k++) {
            int j = lower_bound(pos[prev].begin(), pos[prev].end(), pos[cur][k]) - pos[prev].begin();
            consider(j, k);
            consider(j - 1, k);
        }
        swap(dp, new_dp);
    }
    print(*min_element(dp.begin(), dp.end()));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}