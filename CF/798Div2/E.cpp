#include "bits/stdc++.h"
#include <cfloat>
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

#define lsb(x) __builtin_ctzll(x)

class dsu {
public:
    vector<int> p, sz;
    vector<vector<int>> components;
    int cc;
    int n;

    dsu(int _n) : n(_n) {
        cc = n;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
        components.resize(n);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        p[y] = x;
        sz[x] += sz[y];
        sz[y] = 0;
        cc--;
        return true;
    }
    
    void unite(const vector<pair<int, int>>& edges) {
        for (auto &[u, v] : edges)
            unite(u, v);
    }
    
    void unite(const vector<int> &U, const vector<int> &V) {
        int m = U.size();
        assert(int(V.size()) == m);
        for (int i = 0; i < m; i++)
            unite(U[i], V[i]);
    }
    
    void calculate_components () {
        for (int i = 0; i < n; i++) {
            components[get(i)].emplace_back(i);
        }
    }
};


void solve() {
    int n;
    scan(n);
    vector<int> a(n);
    scan(a);
    const int log = 30;
    dsu d(log);
    for (auto x : a) {
        int bit = lsb(x);
        x ^= 1 << bit;
        while (x > 0) {
            int cur = lsb(x);
            d.unite(bit, cur);
            x ^= 1 << cur;
        }
    }
    vector<vector<int>> vec(30);
    for (auto &x : a) {
        int bit = lsb(x);
        bit = d.get(bit);
        vec[bit].emplace_back(x);
    }
    for (auto &v : vec) {
        if (!v.empty()) {
            dbg(v);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}