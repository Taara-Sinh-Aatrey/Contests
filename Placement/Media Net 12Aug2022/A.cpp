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
const int inf = 1e18L + 5, N = 2e5 + 5;

class segtree {
public:
    struct node {
        int z = 1, o = 0, lazy = 0;

        void apply(int l, int r, int v) {
            swap(z, o);
            lazy ^= 1;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.o = a.o + b.o;
        res.z = a.z + b.z;
        return res;
    }

    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        if (tree[x].lazy != 0) {
            tree[x + 1].apply(l, y, tree[x].lazy);
            tree[z].apply(y + 1, r, tree[x].lazy);
            tree[x].lazy = 0;
        }
    }

    inline void pull(int x, int z) { tree[x] = unite(tree[x + 1], tree[z]); }

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
        push(x, l, r);
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
        push(x, l, r);
        if (ll <= y)
            modify(x + 1, l, y, ll, rr, v...);
        if (rr > y)
            modify(z, y + 1, r, ll, rr, v...);
        pull(x, z);
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
};

int solve(int n, vector<vector<int>> Q) {
    const int mod = 1e9 + 7;
    int sum = 0;
    segtree st(n);
    for (auto &v : Q) {
        int t = v[0], l = v[1], r = v[2];
        if (t == 0) {
            st.modify(l, r, 1);
        }
        else {
            sum += st.get(l, r).o;
        }
    }
    return sum % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    print(solve(5, {{0, 1, 3}, {1, 1, 2}, {0, 0, 4}, {1, 3, 4}}));
    
    
    return 0;
}