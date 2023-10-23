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

// weighted and undirected
class Graph {
public:
    int n; // number of nodes
    int e; // number of edges
    int cc; // number of connected components
    vector<vector<pair<int, int>>> g; // adjacency list
    vector<int> a; // value of each node (usually given in the input)
    vector<int> dist; // dist : bfs distance
    vector<int> depth; // depth : dfs distance
    
    Graph() : n(0), e(0) {}
    
    Graph (int _n) : n(_n), g(_n), e(0) {}
    
    template<typename T>
    Graph (int _n, const vector<T> &edge, bool minus_one = true) : Graph(_n) {
        add(edge, minus_one);
    }
    
    Graph (int _n, const vector<int> &U, const vector<int> &V, const vector<int> &W, bool minus_one = true) : Graph(_n) {
        add(U, V, W, minus_one);
    }
    
    void add(int u, int v, int w, bool minus_one = true) {
        e++;
        u -= minus_one; v -= minus_one;
        g[u].emplace_back(w, v);
        g[v].emplace_back(w, u);
    }
    
    template<typename T>
    void add(const vector<T> &edges, bool minus_one = true) {
        for (auto &[u, v, w] : edges)
            add(u, v, w, minus_one);
    }
    
    void add(const vector<int> &U, const vector<int> &V, const vector<int> &W, bool minus_one = true) {
        assert(U.size() == V.size() && V.size() == W.size());
        for (int i = 0; i < int(U.size()); i++)
            add(U[i], V[i], W[i], minus_one);
    }
    
    // standard bfs
    void bfs(const vector<int> &source = {0}) {
        dist.resize(n, inf);
        queue<int> q;
        for (auto &node : source) {
            q.emplace(node);
            dist[node] = 0;
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto &[weight, child] : g[node]) {
                if (dist[node] + weight < dist[child]) {
                    dist[child] = dist[node] + weight;
                    q.emplace(child);
                }
            }
        }
    }
    
    // normal dfs
    void dfs(int node = 0) {
        // if `depth` vector is empty => dfs is called for the first time, so let's initialize
        if (depth.empty())
            depth.assign(n, -1);
        
        // if `depth[node]` == -1 => dfs is called for a new connected component and node is its root
        if (depth[node] == -1)
            depth[node] = 0;
        
        for (auto &[weight, child] : g[node]) {
            if (depth[child] == -1) {
                depth[child] = depth[node] + weight;
                dfs(child);
            }
        }
    }
    
    // run dfs from every unvisited node
    void dfs_all() {
        depth.assign(n, -1);
        cc = 0;
        for (int node = 0; node < n; node++) {
            if (depth[node] != -1) continue;
            cc++;
            dfs(node);
        }
    }
    
    // returns true if graph contains a cycle
    bool has_cycle() {
        vector<bool> vis(n);
        function<bool(int, int)> dfs = [&] (int node, int parent) -> bool {
            vis[node] = true;
            for(auto &[weight, child] : g[node]) {
                if (child == parent) continue;
                if (vis[child] || dfs(child, node)) return true;
            }
            return false;
        };
        for (int node = 0; node < n; node++) {
            if (vis[node]) continue;
            if (dfs(node, -1)) return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    scan(n, m);
    Graph graph(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scan(u, v, w);
        graph.add(u, v, w);
    }
    graph.bfs();
    dbg(graph.dist);
    graph.dfs();
    dbg(graph.depth);
    dbg(graph.has_cycle());
    string s = "The quick brown fox jumps over the lazy dog";
    s.erase(remove_if(s.begin(), s.end(), [&] (auto &x) {
        return isspace(x);
    }), s.end());
    map<char, int> freq;
    for (auto &ch : s)
        freq[tolower(ch)]++;
    dbg(freq);
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