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
#include <memory>
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
    scan(n);
    vector<int> a(n);
    scan(a, m);
    for (auto &x : a)
        --x;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scan(a, b);
        --a, --b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
    }
    vector<int> ops;
    for (int i = 0; i < n; i++) {
        int j = find(a.begin(), a.end(), i) - a.begin();
        if (i == j)
            continue;
        vector<pair<int, int>> p(n, {-1, -1});
        vector<bool> vis(n);
        queue<int> q;
        q.emplace(i);
        vis[i] = true;
        while (!q.empty() && !vis[j]) {
            int x = q.front();
            q.pop();
            for (auto &[y, idx] : g[x]) {
                if (vis[y]) continue;
                p[y] = {x, idx};
                q.emplace(y);
                vis[y] = true;
                if (y == j) break;
            }
        }
        if (!vis[j]) {
            print(-1);
            return;
        }
        vector<int> vec;
        int x = j;
        while (x != i) {
            ops.emplace_back(p[x].second);
            vec.emplace_back(p[x].second);
            x = p[x].first; 
        }
        for (int w = int(vec.size()) - 2; w >= 0; w--) {
            ops.emplace_back(vec[w]);
        }
        swap(a[i], a[j]);
    }
    print(ops.size());
    print(ops);
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