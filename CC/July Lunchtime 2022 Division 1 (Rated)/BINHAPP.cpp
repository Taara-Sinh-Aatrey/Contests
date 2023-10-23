// tourist's solution
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

// #define int int64_t
const int inf = 1e9 + 5, mod = 1e9 + 7, N = 2e5 + 5;

class segtree {
public:

    struct node {
        int v00 = 0;
        int v01 = 0;
        int v10 = 0;
        int v11 = 0;

        void apply(int l, int r, array<int, 3> v) {
            v00 = max(0, v[2]);
            v01 = v[1];
            v10 = v[0];
            v11 = -1;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.v00 = a.v00 + b.v00;
        res.v01 = max(a.v01 + b.v00, a.v00 + b.v01);
        res.v10 = max(a.v10 + b.v00, a.v00 + b.v10);
        res.v11 = max(max(a.v10 + b.v01, a.v01 + b.v10), max(a.v00 + b.v11, a.v11 + b.v00));
        return res;
    }

    inline void pull (int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }
    
    int n;
    vector<node> tree;
    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }
    
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }
    
    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        node res{};
        if (rr <= y) 
            res = get(x + 1, l, y, ll, rr); 
        else if (ll > y) 
            res = get(z, y + 1, r, ll, rr); 
        else 
            res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
        pull(x, z);
        return res;
    }
    
    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        if (ll <= y) 
            modify(x + 1, l, y, ll, rr, v...);
        if (rr > y) 
            modify(z, y + 1, r, ll, rr, v...);
        pull(x, z);
    }
    
    segtree(int _n) : n(_n) {
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    
    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    
    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }
    
    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
};

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    F func;

    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 64 - __builtin_clzll(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 64 - __builtin_clzll(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve() {
    int n, q;
    scan(n, q);
    vector<int> pref(n), suf(n), in(n), sum(n);
    for (int i = 0; i < n; i++) {
        int len;
        string s;
        scan(len, s);
        int cur = 0;
        for (int j = 0; j < len; j++) {
            cur += (s[j] == '1' ? 1 : -1);
            pref[i] = max(pref[i], cur);
        }
        sum[i] = cur;
        cur = 0;
        for (int j = len - 1; j >= 0; j--) {
            cur += (s[j] == '1' ? 1 : -1);
            suf[i] = max(suf[i], cur);
        }
        int mn = 0;
        cur = 0;
        for (int j = 0; j < len; j++) {
            cur += (s[j] == '1' ? 1 : -1);
            in[i] = max(in[i], cur - mn);
            mn = min(mn, cur);
        }
    }
    SparseTable<int> sp(in, [&](int i, int j) { return max(i, j); });
    vector<array<int, 3>> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {pref[i], suf[i], sum[i]};
    }
    segtree st(v);
    while (q--) {
        int l, r;
        scan(l, r);
        --l; --r;
        int ans = sp.get(l, r);
        auto nd = st.get(l, r);
        print(max({ans, nd.v00, nd.v01, nd.v10, nd.v11}));
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