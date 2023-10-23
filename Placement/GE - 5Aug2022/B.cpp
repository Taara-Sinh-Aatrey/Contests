#include "bits/stdc++.h"
using namespace std;

const int inf = 1e9 + 5;

class segtree {
public:
    struct node {
        int mn = 0, cnt = 0, lazy = 0;

        void apply(int l, int r, int v) {
            mn += v;
            lazy += v;
            cnt = 1;
        }
    };

    node unite(const node &a, const node &b) const {
        node res = {a.mn, a.cnt, 0};
        if (b.mn < res.mn) res = {b.mn, b.cnt, 0};
        else if (b.mn == res.mn) res.cnt += b.cnt;
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

    int find_first(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> A(2, vector<int>(n, inf));
    vector<int> even(n, inf), odd(n, inf);
    int score = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        score = a[i] - score;
        A[i % 2][i] = score;
    }
    vector<segtree> st(2, segtree(n));
    for (int i = 0; i < 2; i++) {
        st[i] = segtree(A[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int p = i % 2;
        // for (int j = 0; j < n; j++) {
        //     cout << st[j % 2].get(j, j).mn << " \n"[j == n - 1];
        // }
        // cout << endl;
        
        auto func = [&] (const segtree::node &x) {
            return x.mn < 0;
        };
        
        int idx = n;
        for (int parity = 0; parity < 2; parity++) {
            int ret = st[parity].find_first(0, 0, n - 1, i, n - 1, func);
            idx = min(idx, ret == -1 ? n : ret);
        }
        
        // dbg(i, idx);
        
        assert(idx > i);
        
        int cur = 0;
        for (int parity = 0; parity < 2; parity++) {
            auto res = st[parity].get(i, idx - 1);
            if (res.mn == 0) {
                cur += res.cnt;
            }
        }
        
        ans += cur;
        
        st[p].modify(i, n - 1, -a[i]);
        if (i + 1 < n)
            st[1 - p].modify(i + 1, n - 1, a[i]);
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}