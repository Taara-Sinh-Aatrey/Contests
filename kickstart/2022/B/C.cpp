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
    int n, d;
    scan(n, d);
    vector<int> a(n);
    scan(a);
    auto consider = [&] (map<int, int> &mp, int key, int val) {
        if (mp.count(key)) {
            amin(mp[key], val);
        }
        else {
            mp[key] = val;
        }
    };
    auto convert = [&] (int val, int target) {
        int mv1 = (target >= val ? target - val : d + target - val);
        int mv2 = (target <= val ? val - target : val + d - target);
        return min(mv1, mv2);
    };
    vector<vector<map<int, int>>> dp(n, vector<map<int, int>>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            auto Solve = [&] (int me) {
                int target = me;
                int x = i, y = j;
                while (x <= y && a[x] == target) {
                    x++;
                }
                while (x <= y && a[y] == target) {
                    y--;
                }
                if (x > y) {
                    consider(dp[i][j], target, 0);
                }
                else {
                    for (auto &[val, mv] : dp[x][y]) {
                        consider(dp[i][j], target, mv + convert(val, target));
                    }
                }
            };
            Solve(a[i]);
            Solve(a[j]);
        }
    }
    int ans = inf;
    for (auto &[val, mv] : dp[0][n - 1]) {
        amin(ans, mv + convert(val, 0));
    }
    print(ans);
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