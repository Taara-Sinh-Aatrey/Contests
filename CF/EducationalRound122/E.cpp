#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

class dsu {
public:
    vector<int> p;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // input
    int n, m;
    cin >> n >> m;    
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());
    
    // find weight of spanning tree for a given x
    auto Mst = [&] (int x) {
        sort(edges.begin(), edges.end(), [&] (auto &a, auto &b) {
            return abs(x - a[0]) < abs(x - b[0]);
        });
        dsu d(n);
        int sum = 0, mult = 0;
        for (auto &[w, u, v] : edges) {
            if (!d.unite(u, v)) 
                continue;
            if (x >= w) {
                sum -= w;
                mult++;
            }
            else {
                sum += w;
                mult--;
            }
        }
        return pair(sum, mult);
    };
    
    // find all the points where order of the edges might change
    vector<int> cutoffs{0};
    for (int i = 0; i < int(edges.size()); i++) {
        cutoffs.emplace_back(edges[i][0]);
        for (int j = i + 1; j < int(edges.size()); j++) {
            int sum = (edges[i][0] + edges[j][0]);
            int half = sum / 2;
            if (sum % 2 == 0) {
                // [10, 20] -> [10, 14], [15, 15], [16, 20]
                // put 10, 15 and 16
                // cutoffs.emplace_back(edges[i][0]); // already considered
                cutoffs.emplace_back(half);
                cutoffs.emplace_back(half + 1);
            }
            else {
                // [10, 19] -> ([10, 14] [15, 19])
                // put 10 and 15
                // cutoffs.emplace_back(edges[i][0]); // already considered
                cutoffs.emplace_back(half + 1);
            }
        }
        
    }
    
    // remove duplicates
    sort(cutoffs.begin(), cutoffs.end());
    cutoffs.resize(unique(cutoffs.begin(), cutoffs.end()) - cutoffs.begin());
    
    // preprocess answer for all the cutoffs
    // this will be useful since the number of queries can be upto 1e7
    // whereas the size of cutoffs will be only upto 9e4
    vector<pair<int, int>> msts;
    for (auto &x : cutoffs) {
        msts.emplace_back(Mst(x));
    }
    
    int Xor = 0;
    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    int x;
    
    for (int i = 0; i < k; i++) {
        
        if (i < p)
            cin >> x;
        else
            x = (x * a + b) % c;
        
        int idx = prev(upper_bound(cutoffs.begin(), cutoffs.end(), x)) - cutoffs.begin();
        auto [sum, mult] = msts[idx];
        int ans = sum + mult * x;
        Xor ^= ans;
    }
    
    cout << Xor << '\n';
    
    return 0;
}