#include "bits/stdc++.h"
using namespace std;

class segtree {
public:
    struct node {
        // don't forget to set default value (used for leaves)
        // not necessarily neutral element!
        long mx = 0, idx = 0;

        void apply(long l, long r, long v) {
            mx = v;
            idx = l;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res = a;
        if(b.mx > res.mx) {
            res = b;
        }
        return res;
    }

    inline void push(long x, long l, long r) {
    }

    inline void pull(long x, long z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    long n;
    vector<node> tree;

    void build(long x, long l, long r) {
        if (l == r) {
            return;
        }
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }

    template <typename M>
    void build(long x, long l, long r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }

    node get(long x, long l, long r, long ll, long rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } 
        else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } 
            else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(long x, long l, long r, long ll, long rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v...);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }

    long find_first_knowingly(long x, long l, long r, const function<bool(const node&)> &f) {
        if (l == r) {
            return f(tree[x]) ? l : -1;
        }
        push(x, l, r);
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        long res = -1;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } 
        else if(f(tree[z])) {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }

    long find_first(long x, long l, long r, long ll, long rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        long res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    long find_last_knowingly(long x, long l, long r, const function<bool(const node&)> &f) {
        if (l == r) {
            return f(tree[x]) ? l : -1;
        }
        push(x, l, r);
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        long res = -1;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } 
        else if(f(tree[x + 1])) {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }

    long find_last(long x, long l, long r, long ll, long rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        long y = (l + r) >> 1;
        long z = x + ((y - l + 1) << 1);
        long res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    segtree(long _n) : n(_n) {
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

    node get(long ll, long rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(long p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(long ll, long rr, const M&... v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }

    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once

    long find_first(long ll, long rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }

    long find_last(long ll, long rr, const function<bool(const node&)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};

vector<long> maximisingSweetness(vector<int> A, vector<int> B, vector<int> C) {
    long n = A.size(), m = C.size();
    vector<pair<long, long>> a;
    for(long i = 0; i < n; i++) {
        a.emplace_back(A[i], B[i]);
    }
    sort(a.begin(), a.end());
    
    segtree st(n);
    for(long i = 0; i < n; i++) {
        st.modify(i, i, a[i].second);
    }
    sort(C.begin(), C.end());
    
    long sweetness = 0, sweets = 0;
    long j = -1;
    for(long i = 0; i < m; i++) {
        while(j + 1 < n && a[j + 1].first <= C[i]) j++;
        if(j == -1) continue;
        auto res = st.get(0, j);
        if(res.mx == 0) continue;
        sweetness += res.mx;
        sweets++;
        st.modify(res.idx, res.idx, 0);
    }
    return {sweets, sweetness};
}

signed main() {
    auto vec = maximisingSweetness({10, 2, 5}, {40, 90, 20}, {3, 5, 4});
    cout << vec[0] << " " << vec[1] << endl;
    return 0;
}