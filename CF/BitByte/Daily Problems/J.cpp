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
    string s;
    scan(s);
    map<char, int> f;
    for (auto &ch : s)
        f[ch]++;
    char mx = '?';
    for (auto &[x, y] : f) {
        if (mx == '?' || y > f[mx])
            mx = x;
    }
    int n = s.size();
    vector<int> a, b{0};
    for (int i = 2; i <= n / 2; i++)
        a.emplace_back(i - 1);
    for (int i = n / 2 + 1; i <= n; i++) {
        int x = 0;
        for (int j = 2; j < i; j++) {
            if (i % j == 0)
                x++;
        }
        if (x > 0)
            a.emplace_back(i - 1);
        else
            b.emplace_back(i - 1);
    }
    if (f[mx] < a.size()) {
        print("NO");
        return;
    }
    string ans(n, '?');
    for (auto &i : a) {
        ans[i] = mx;
        f[mx]--;
    }
    for (auto &[x, y] : f) {
        while (y > 0) {
            y--;
            ans[b.back()] = x;
            b.pop_back();
        }
    }
    print("YES");
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