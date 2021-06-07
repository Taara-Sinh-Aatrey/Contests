/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.05.2021 11:42:09
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

class graph{
public: 
    int n; // number of nodes
    int e; // number of edges
    int cc; // number of connected components
    int scc; // number of strongly connected components
    vector<vector<pair<int, int>>> g, rg; // adjacency list, reverse adjacency list
    vector<int> value; // value of each node of graph (usually given in the input)
    vector<int> bfs_dist, depth, dijkstra_dist, topo_order;
    vector<int> when; // when[u] represents the scc which u is a part of
    vector<int> cnt; // count of nodes (or anything similar) for every scc
    vector<vector<int>> sccs; // scc[i] contains all the nodes which are part of ith scc

    graph(int _n){
        n = _n;
        g.resize(n + 1);
        e = 0;
    }

    // sets value of each node
    void set_value(vector<int> a) {
        value = a;
    }

    /* weight should be set to 0 or 1 or any neutral value
    if weight is not given as a input */

    void add(int u, int v, int w, bool directed = false) {
        e++;
        g[u].emplace_back(w, v);
        if(!directed) {
            g[v].emplace_back(w, u);
        }
    }

    void bfs(vector<int> src) {
        bfs_dist.resize(n + 1, INF);
        queue<int> q;
        for(int ele: src) {
            q.push(ele);
            bfs_dist[ele] = 0;
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto& [w, v]: g[u]) {
                if(bfs_dist[v] > bfs_dist[u] + w) {
                    bfs_dist[v] = bfs_dist[u] + w;
                    q.push(v);
                }
            }
        }
    }

    void dfs(int u, int p = -1) {
        if(p == -1) {
            depth.resize(n + 1, -1);
            depth[u] = 0;
        }

        for(auto& [v, w]: g[u]){
            if(depth[v] == -1) {
                depth[v] = depth[u] + w;
                dfs(v, u);
            }
        }
    }

    void dijkstra(vector<int> src) {
        dijkstra_dist.resize(n + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int ele: src){
            pq.emplace(0, ele);
            dijkstra_dist[ele] = 0;
        }
        while(!pq.empty()){
            auto [dist, u] = pq.top();
            pq.pop();
            if(dist > dijkstra_dist[u]) {
                continue;
            }
            for(auto& [v, w]: g[u]) {
                if(dijkstra_dist[v] > dist + w) {
                    dijkstra_dist[v] = dist + w;
                    pq.emplace(dijkstra_dist[v], v);
                }
            }
        }
    }

    bool toposort() {
        topo_order.clear();
        vector<int> vis(n, false), act(n, false);

        function<bool(int)> Dfs = [&](int u) -> int {
            vis[u] = act[u] = true;
            for (auto& [w, v]: g[u]) {
                if(act[v]) {
                    return false;
                } else if(!vis[v]) {
                    if(!Dfs(v)) {
                        return false;
                    }
                }
            }
            act[u] = false;
            topo_order.emplace_back(u);
            return true;
        };

        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                if(!Dfs(u)) {
                    return false;
                }
            }
        } 
        reverse(topo_order.begin(), topo_order.end());
        return true;
    }

    void get_scc() {
        sccs.clear();
        scc = 0;
        topo_order.clear();
        when.assign(n, -1);
        vector<int> vis(n, false);
        rg.assign(n, vector<pair<int, int>>());
        for(int u = 0; u < n; u++) {
            for(auto& [w, v]: g[u]) {
                rg[v].emplace_back(w, u);
            }
        }

        function<void(int)> Dfs = [&](int u) {
            vis[u] = true;
            for (auto& [w, v]: g[u]) {
                if(!vis[v]) {
                    Dfs(v);
                }
            }
            topo_order.emplace_back(u);
        };

        for(int u = 0; u < n; u++) {
            if(!vis[u]) {
                Dfs(u);
            }
        } 
        reverse(topo_order.begin(), topo_order.end());

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;
            sccs[scc].emplace_back(u);
            when[u] = scc;
            if(!value.empty()) {
                cnt[scc] += value[u];
            }
            for (auto& [w, v]: rg[u]) {
                if(!vis[v]) {
                    cnt[scc] += w;
                    dfs(v);
                }
            }
        };

        vis.assign(n, false);
        for(auto u: topo_order) {
            if(!vis[u]) {
                cnt.emplace_back(0);
                sccs.emplace_back(vector<int>());
                dfs(u);
                scc++;
            }
        }
    };

};

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    cin >> a;

    graph g(n);
    g.set_value(a);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.add(u, v, 0, 1);
    }

    g.get_scc();
    vector<int> dp = g.cnt;
    for(int i = 0; i < g.scc; i++) {
        for(auto& u: g.sccs[i]) {
            for(auto& [w, v]: g.g[u]) {
                if(g.when[u] == g.when[v]) continue;
                amax(dp[g.when[v]], dp[i] + g.cnt[g.when[v]]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
