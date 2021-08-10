/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.07.2021 12:29:02
**/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

void solve() {
    
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    const int lvl = 19;
    vector<int> depth(n);
    vector<vector<int>> p(lvl, vector<int>(n, -1));
    
    function<void(int, int)> dfs = [&](int cur, int prev) {
        depth[cur] = (prev == -1 ? 0 : depth[prev] + 1);
        p[0][cur] = prev;        
        for(auto& nxt : g[cur]) {
            if(nxt == prev) continue;
            dfs(nxt, cur);
        }
    };
    
    dfs(0, -1);
    
    
    
    for(int i = 1; i < lvl; i++){
        for(int node = 0; node < n; node++){
            if(p[i - 1][node] != -1){
                p[i][node] = p[i - 1][p[i - 1][node]];
            }
        }
    }
    
    auto get = [&](int node, int dis) {
        for (int i = lvl - 1; i >= 0; i--)
            if (dis >> i & 1) 
                node = p[i][node];
        return node;
    };
    
    auto find_lca = [&](int u, int v) {
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
    
    auto is_ancestor = [&](int u, int v) {
        return depth[v] < depth[u] && v == get(u, depth[u] - depth[v]);
    };
    
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for(int& x: a) {
            cin >> x, --x;
        }
        
        vector<int> order(k);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int& i, const int& j) {
            return depth[a[i]] > depth[a[j]];
        });
                
        bool ok = true;
        vector<int> paths;
        for(int it = 0; it < k; it++) {
            
            int v = a[order[it]];
            int ancestor = 0;
            for(int& u : paths) {
                ancestor += is_ancestor(u, v);
            }
            
            if((ancestor == 2 && v != find_lca(paths[0], paths[1])) || (ancestor == 0 && paths.size() >= 2)) {
                ok = false;
                break;
            }
            
            if(ancestor == 0) paths.emplace_back(v);
        }
        
        cout << (ok ? "YES" : "NO") << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}