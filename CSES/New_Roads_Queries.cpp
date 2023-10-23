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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

int day = 0;
vector<vector<int>> g;
vector<int> depth;
vector<vector<int>> p;
const int lvl = 15;

class dsu {
public:
    vector<int> p, days;
    int n, next;

    dsu(int _n) : n(_n) {
        p.resize(n);
        days.resize(n);
        iota(p.begin(), p.end(), 0);
        next = n;
    }

    inline int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    
    inline bool united(int x, int y) {
        x = get(x), y = get(y);
        return x == y;
    }

    inline bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return false;
        g.resize(next + 1);
        p.resize(next + 1);
        days.resize(next + 1);
        p[x] = next;
        p[y] = next;
        p[next] = next;
        g[next].emplace_back(x);
        g[next].emplace_back(y);
        days[next] = day;
        next++;
        return true;
    }
};


class LCA {
public:
    
    int n;
    vector<int> &nodes;
    int root;
    
    LCA(vector<int>& _nodes, int _root) : nodes(_nodes), root(_root) {
        n = nodes.size();
        function<void(int, int)> dfs = [&](int u, int par) {
            p[0][u] = par;
            depth[u] = par == -1 ? 0 : depth[par] + 1;
            for(auto& v : g[u]) {
                if(v == par) continue;
                dfs(v, u);
            }    
        };
        dfs(root, -1);
        for (int i = 1; i < lvl; i++){
            for (auto &node : nodes) {
                if(p[i - 1][node] != -1){
                    p[i][node] = p[i - 1][p[i - 1][node]];
                }
            }
        }
    }
    
    int get (int node, int dis) {
        for (int i = lvl - 1; i >= 0; i--)
            if (dis >> i & 1) 
                node = p[i][node];
        return node;
    };
    
    int find_lca (int u, int v) {
        if (depth[u] > depth[v]) { 
            swap(u, v);
        }

        v = get(v, depth[v] - depth[u]);

        if (u == v) 
            return u;

        for (int i = lvl - 1; i >= 0; i--){
            if (p[i][u] != p[i][v]){
                u = p[i][u];
                v = p[i][v];
            }
        }
        return p[0][u];
    };
};


void solve() {
    int n, m, q;
    scan(n, m, q);
    dsu d(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scan(u, v), --u, --v;
        day = i;
        d.unite(u, v);
    }
    int sz = d.next;
    g.resize(sz);
    depth.resize(sz);
    p.resize(lvl, vector<int>(sz, -1));
    vector<vector<int>> comps(sz);
    for (int i = 0; i < sz; i++) {
        comps[d.get(i)].emplace_back(i);
    }
    vector<LCA> lcas;
    for (int i = 0; i < sz; i++) {
        lcas.emplace_back(LCA(comps[i], i));
    }
    while (q--) {
        int u, v;
        scan(u, v), --u, --v;
        if (!d.united(u, v)) {
            print(-1);
        }
        else {
            int comp = d.get(u);
            print(d.days[lcas[comp].find_lca(u, v)]);
        }
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