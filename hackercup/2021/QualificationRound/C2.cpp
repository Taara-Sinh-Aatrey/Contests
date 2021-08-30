/**
 *    author:  Taara Sinh Aatrey
 *    created: 06.06.2021 16:10:43
**/

#include <bits/stdc++.h>
#include <type_traits>
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


void solve() {

    int n, k;
    cin >> n >> k;
        
    vector<int> A(n);
    cin >> A;
    
    vector<vector<int>> G(n, vector<int>(n, 0));
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    
    vector<int> leaves;
    for(int i = 1; i < n; i++) {
        int deg = 0;
        for(int j = 0; j < n; j++) {
            deg += G[i][j];
        }
        if(deg == 1) {
            leaves.emplace_back(i);
        }
    }
    
    if(k == 0 || n == 1) {
        cout << A[0] << '\n';
        return;
    }
    
    int best = 0;
    for(int i = 0; i < leaves.size(); i++) {
        for(int j = i + 1; j <= leaves.size(); j++) {
            int sp1 = leaves[i];
            int sp2 = j < leaves.size() ? leaves[j] : -1;
            auto g = G;
            auto a = A;
            int ans = 0;
                    
            for(int it = 0; it <= k; it++) {
                vector<pair<int, int>> mx(n), smx(n);
                vector<int> p(n, -1);
                vector<bool> vis(n, false);
                int node = -1;
                function<void(int)> dfs = [&](int u) {
                    vis[u] = true;
                    int cnt = 0;
                    mx[u] = smx[u] = {0, u};
                    for(int v = 0; v < n; v++) {
                        if(g[u][v] == 1 && !vis[v]) {
                            p[v] = u;
                            dfs(v);
                            if(mx[v].first + a[v] > mx[u].first) {
                                smx[u] = mx[u];
                                mx[u] = mx[v];
                                mx[u].first += a[v];
                            }
                            else if(mx[v].first + a[v] > smx[u].first) {
                                smx[u] = mx[v];
                                smx[u].first += a[v];
                            }
                        }
                    }
                    if(node == -1 || smx[u].first + mx[u].first + a[u] > smx[node].first + mx[node].first + a[node]) {
                        node = u;
                    }
                };
                
                for(int i = 0; i < n; i++) {
                    if(vis[i]) continue;
                    dfs(i);
                    if(it <= 1) break;
                }
                
                int node1 = -1, node2 = -1;
                if(it <= 1) {
                    node = 0;
                    if(it == 0) {
                        node1 = sp1;
                    }
                    else {
                        node1 = sp2;
                    }
                }
                else {
                    node1 = mx[node].second, node2 = smx[node].second;
                }
                                
                while(node1 >= 0 && node1 != node) {
                    ans += a[node1];
                    a[node1] = 0;
                    int par = p[node1];
                    if(par >= 0) {
                        g[node1][par] = 0;
                        g[par][node1] = 0;
                    } 
                    node1 = par;
                }
                
                if(it == 1 && sp2 != -1 && node1 != node) {
                    ans = 0;
                    break;
                }
                
                while(node2 >= 0 && node2 != node) {
                    ans += a[node2];
                    a[node2] = 0;
                    int par = p[node2];
                    if(par >= 0) {
                        g[node2][par] = 0;
                        g[par][node2] = 0;
                    } 
                    node2 = par;
                }
                
                if(node != -1) {
                    ans += a[node];
                    a[node] = 0;
                }
                
            }
            amax(best, ans);
        }
    }
    cout << best << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}