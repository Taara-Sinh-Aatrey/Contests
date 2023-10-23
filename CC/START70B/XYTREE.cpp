#include "bits/stdc++.h"
using namespace std;

#define int int64_t

template<typename T>
class fenwick {
public:
    int n;
    vector<T> tree;
    fenwick() {}

    fenwick(int _n) : n(_n) {
        tree.resize(n + 1, 0);
    }

    fenwick(vector<T> &a) {
        n = int(a.size());
        tree.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
            modify(i, a[i]);
    }
    
    // increments the value of idx by val
    void modify(int idx, T val) {
        idx += 1;
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    } 

    // returns the sum of a[0..idx]
    T get(int idx) {
        idx += 1;
        T ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & (-idx);
        }
        return ret;
    }
    
    // returns the sum of a[L..R]
    T get(int L, int R) {
        return get(R) - get(L - 1);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v, --u, --v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        vector<int> st(n), en(n), sz(n, 1);
        int timer = 0;
        function<void(int, int)> dfs = [&] (int u, int par) {
            st[u] = timer++;
            for (auto& v : g[u]) {
                if (v == par) 
                    continue;
                dfs(v, u);
                sz[u] += sz[v];
            }
            en[u] = timer;
        };
        dfs(0, -1);
        fenwick<int> fenw(n);
        int ans = n - 1;
        int q;
        cin >> q;
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int node;
                cin >> node, --node;
                int me = fenw.get(st[node], st[node]);
                if (me == 1) {
                    continue;
                }
                if (g[node].size() - (node != 0 ? 1 : 0) == 0) {
                    // leaf node
                    fenw.modify(st[node], 1);
                    ans -= node != 0;
                }
                else {
                    int cnt = fenw.get(st[node], en[node] - 1);
                    if (cnt == sz[node] - 1) {
                        if (node == 0) {
                            ans = n - 1;
                        }
                        else {
                            ans--;
                        }
                        fenw.modify(st[node], 1);
                    }
                }
            }
            else {
                cout << ans << '\n';
            }
        }
    }
    return 0;
}