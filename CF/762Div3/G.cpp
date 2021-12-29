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
#include <unordered_map>
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

class dsu {
public:
    vector<int> p, val;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        val.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            amin(val[y], val[x]);
            return true;
        }
        return false;
    }
};

void solve() {
    int n, k;
    scan(n, k);
    map<int, set<pair<int, int>>> X, Y;
    dsu d(n);
    for (int i = 0; i < n; i++) {
        int x, y, v;
        scan(x, y, v);
        d.val[i] = v;
        auto it = X[x].emplace(y, i).first;
        if (it != X[x].begin() && prev(it)->first >= y - k) {
            d.unite(i, prev(it)->second);
        }
        if (next(it) != X[x].end() && next(it)->first <= y + k) {
            d.unite(i, next(it)->second);
        }
        it = Y[y].emplace(x, i).first;
        if (it != Y[y].begin() && prev(it)->first >= x - k) {
            d.unite(i, prev(it)->second);
        }
        if (next(it) != Y[y].end() && next(it)->first <= x + k) {
            d.unite(i, next(it)->second);
        }
    }
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (d.get(i) == i) {
            a.emplace_back(d.val[i]);
        }
    }
    sort(a.begin(), a.end());
    int ans = -1, i = 0, j = int(a.size()) - 1;
    while (i <= j) {
        ans++;
        j--;
        while (i <= j && a[i] == ans) {
            i++;
        }
    }
    print(ans);
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