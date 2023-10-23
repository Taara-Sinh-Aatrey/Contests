#include "bits/stdc++.h"
using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

class segtree {
public:
    struct node {
        int lazy = 0, mx = 0;

        void apply(int l, int r, int v) {
            mx += v;
            lazy += v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        assert(a.mx <= b.mx);
        res.mx = max(a.mx, b.mx);
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

    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return f(tree[x]) ? l : -1;
        }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (f(tree[x + 1]))
            res = find_first_knowingly(x + 1, l, y, f);
        else if(f(tree[z]))
            res = find_first_knowingly(z, y + 1, r, f);
        pull(x, z);
        return res;
    }

    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y)
            res = find_first(x + 1, l, y, ll, rr, f);
        if (rr > y && res == -1)
            res = find_first(z, y + 1, r, ll, rr, f);
        pull(x, z);
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return f(tree[x]) ? l : -1;
        }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (f(tree[z]))
            res = find_last_knowingly(z, y + 1, r, f);
        else if(f(tree[x + 1]))
            res = find_last_knowingly(x + 1, l, y, f);
        pull(x, z);
        return res;
    }

    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1, z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y)
            res = find_last(z, y + 1, r, ll, rr, f);
        if (ll <= y && res == -1)
            res = find_last(x + 1, l, y, ll, rr, f);
        pull(x, z);
        return res;
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

    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once

    int find_first(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }

    int find_last(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};

/*

*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pref = a;
    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }
    segtree st(pref);
    int q;
    cin >> q;
    vector<array<int, 3>> Q(q);
    map<int, int> book;
    map<int, vector<int>> release;
    set<int> points;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        Q[i] = {l, r, x};
        book[l] = i;
        release[r].emplace_back(i);
        points.emplace(l);
        points.emplace(r);
    }
    vector<int> ans(q);
    for (auto &p : points) {
        if (book.count(p)) {
            auto idx = book[p];
            auto [l, r, x] = Q[idx];
            assert(l == p);
            auto hotel = st.find_first(0, n - 1, [&] (const segtree::node &nd) {
                return nd.mx >= x;
            });
            ans[idx] = hotel;
            st.modify(hotel, n - 1, -1);
        }
        for (auto &idx : release[p]) {
            auto [l, r, x] = Q[idx];
            assert(r == p);
            st.modify(ans[idx], n - 1, 1);
        }
    }
    for (auto &x : ans) {
        cout << x + 1 << " ";
    }
}