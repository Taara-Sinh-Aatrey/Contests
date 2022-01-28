#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
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
    int n, m;
    scan(n, m);
    array<int, 3> init = {-1, -1, -1};
    vector<vector<array<int, 3>>> twos(10, vector<array<int, 3>>(10, init));
    vector<vector<vector<array<int, 3>>>> threes(10, twos);
    for (int i = 0; i < n; i++) {
        string s;
        scan(s);
        for (int j = 0; j + 1 < m; j++) {
            twos[s[j] - '0'][s[j + 1] - '0'] = {j, j + 1, i};
        }
        for (int j = 0; j + 2 < m; j++) {
            threes[s[j] - '0'][s[j + 1] - '0'][s[j + 2] - '0'] = {j, j + 2, i};
        }
    }
    string s;
    scan(s);
    vector<array<int, 3>> idx(m, init);
    for (int i = 0; i < m; i++) {
        if (i > 0 && idx[i - 1] == init)
            continue;
        if (i + 1 < m && twos[s[i] - '0'][s[i + 1] - '0'] != init)
            idx[i + 1] = twos[s[i] - '0'][s[i + 1] - '0'];
        if (i + 2 < m && threes[s[i] - '0'][s[i + 1] - '0'][s[i + 2] - '0'] != init)
            idx[i + 2] = threes[s[i] - '0'][s[i + 1] - '0'][s[i + 2] - '0'];
    }
    if (idx[m - 1] == init) {
        print(-1);
        return;
    }
    vector<array<int, 3>> ans;
    int i = m - 1;
    while (i >= 0) {
        auto [l, r, x] = idx[i];
        ans.push_back({l + 1, r + 1, x + 1});
        i -= r - l + 1;
    }
    reverse(ans.begin(), ans.end());
    print(ans.size());
    for (auto &x : ans) {
        print(x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}