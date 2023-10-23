#include "bits/stdc++.h"
#include <algorithm>
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
    map<char, int> hash = {{'R', 0}, {'G', 1}, {'B', 2}};
    for (auto &x : a) {
        char y;
        cin >> y;
        x = hash[y];
    }
    vector<vector<int>> cnt(n + 1, vector<int>(3));
    for (int i = n - 1; i >= 0; i--) {
        cnt[i] = cnt[i + 1];
        cnt[i][a[i]]++;
    }
    int ans = 0;
    vector<int> order(3);
    iota(order.begin(), order.end(), 0);
    do {
        int x = order[0], y = order[1], z = order[2];
        for (int i = 0; i < n; i++) {
            if (a[i] != x)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (a[j] != y)
                    continue;
                ans += cnt[j + 1][z];
                int k = j + j - i;
                ans -= k < n && a[k] == z;
            }
        }
    } while (next_permutation(order.begin(), order.end()));
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