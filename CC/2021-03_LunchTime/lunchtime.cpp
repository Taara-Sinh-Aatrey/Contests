#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define vt vector

const int INF = 1e18L + 5;

// segtree for max (min and maybe sum should work the same) with assignment modification
// for increment modification, code should be modified accordingly

class segtree {
 public:
  struct node {
    // don't forget to set default value (used for leaves)
    // not necessarily neutral element!

    // declaring variables (always change this according to the question)
    int mx = -INF;
    int cnt = 0;

    // this function is called to update a node which contains information
    // of range [l, r], currently we need to do something with the value "v" for [l, r]
    void apply(int l, int r, int v) {
      mx = v;
      cnt = r - l + 1;
    }
  };

  // function to merge result of two child query 
  node unite(const node &a, const node &b) const {
    node res;
    res.mx = max(a.mx, b.mx);
    res.cnt = (a.mx > b.mx ? a.cnt : (a.mx < b.mx ? b.cnt : a.cnt + b.cnt));
    return res;
  }

  // lazy propagation
  // uncomment the code when lazy propagation is required
  // when you need to update a range
  inline void push(int x, int l, int r) {
    // int y = (l + r) >> 1;
    // int z = x + ((y - l + 1) << 1);
    // if (tree[x].lazy != 0) {
    //   tree[x + 1].apply(l, y, tree[x].lazy);
    //   tree[z].apply(y + 1, r, tree[x].lazy);
    //   tree[x].lazy = 0;
    // }
  }
 
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
 
  int n;
  vector<node> tree;
 
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
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
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
 
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
  }
 
  template <typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M&... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
 
  int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
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
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
 
  int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
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
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
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



void solve() {
    int n;
    cin >> n;
    vt<int> a(n);

    segtree seg_tree(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        seg_tree.modify(i, i, a[i]);
    }

    vt<int> ri(n, n), le(n, -1);

    stack<int> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if(!st.empty()) {
            ri[i] = st.top();
        }

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if(!st.empty()) {
            le[i] = st.top();
        }

        st.push(i);
    }

    for(int i = 0; i < n; i++) {
        auto res = seg_tree.get(le[i] + 1, ri[i] - 1);
        assert(res.mx == a[i]);
        cout << res.cnt - 1 << " ";
    }

    cout << '\n';

}

signed main()
{

#ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}



