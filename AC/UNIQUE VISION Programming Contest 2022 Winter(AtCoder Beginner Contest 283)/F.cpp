/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.12.2022 16:54:32
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int inf = 1e18L + 5;

class segtree {
public:
    struct node {
        int mn = 0, lazy = 0;

        void apply(int l, int r, int v) {
            mn += v;
            lazy += v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res = a;
        if (b.mn < res.mn) {
            res = b;
        }
        res.lazy = 0;
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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> ans(n, inf);
    
    auto process = [&] (vector<int> ord, int coeff, int offset) {
        // inc for right, dec for left
        vector<int> inc(n), dec(n);
        iota(inc.begin(), inc.end(), 0);
        iota(dec.rbegin(), dec.rend(), 0);
        for (int i = 0; i < n; i++) {
            inc[i] += coeff * a[i] + offset;
            dec[i] += coeff * a[i] + offset;
        }
        segtree Inc(inc), Dec(dec);
        for (auto &i : ord) {
            Inc.modify(i, i, inf);
            Dec.modify(i, i, inf);
            Inc.modify(0, n - 1, -1);
            Dec.modify(0, n - 1, -1);
            if (i + 1 <= n - 1) {
                auto res = Inc.get(i + 1, n - 1);
                ans[i] = min(ans[i], res.mn - i);
            }
            if (i - 1 >= 0) {
                auto res = Dec.get(0, i - 1);
                ans[i] = min(ans[i], res.mn - (n - 1 - i));
            }
        }
    };
    
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&] (auto &x, auto &y) {
        return a[x] < a[y];
    });
    
    // consider bigger numbers
    process(ord, 1, 0);
    
    // consider smaller numbers
    reverse(ord.begin(), ord.end());
    process(ord, -1, n + 1);
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}