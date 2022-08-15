/**
 *    author:  Taara Sinh Aatrey
 *    created: 15.08.2022 15:06:54
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> L(t), R(t);
    vector<int64_t> res(t);
    int mx = 0;
    for (int tt = 0; tt < t; tt++) {
        cin >> L[tt] >> R[tt];
        int len = R[tt] - L[tt] + 1;
        res[tt] = (int64_t) len * (len - 1) * (len - 2) / 6;
        mx = max(mx, R[tt]);
    }
    vector<vector<int>> Ls(mx + 1), divs(mx + 1);
    for (int i = 1; i <= mx; i++) {
        for (int j = i << 1; j <= mx; j += i) {
            divs[j].emplace_back(i);
        }
    }
    for (int tt = 0; tt < t; tt++) {
        Ls[R[tt]].emplace_back(tt);
    }
    fenwick<int64_t> fenw(mx + 1);
    for (int r = 1; r <= mx; r++) {
        for (int j = 0; j < divs[r].size(); j++) {
            fenw.modify(divs[r][j], divs[r].size() - 1 - j);
        }
        for (int tt: Ls[r]) {
            int l = L[tt];
            res[tt] -= fenw.get(l, r);
            int low = 4 * l, high = 2 * r;
            low += 12 - ((low - 1) % 12 + 1);
            high -= high % 12;
            res[tt] -= max<int>(0, (high - low) / 12 + 1);
            low = 5 * l, high = 2 * r;
            low += 30 - ((low - 1) % 30 + 1);
            high -= high % 30;
            res[tt] -= max<int>(0, (high - low) / 30 + 1);
        }
    }
    for (int tt = 0; tt < t; tt++) {
        cout << res[tt] << '\n';
    }
    return 0;
}