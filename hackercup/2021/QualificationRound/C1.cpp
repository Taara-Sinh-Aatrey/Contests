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

    int n;
    cin >> n;
    
    int k = 1;
    
    vector<int> A(n);
    cin >> A;
    
    vector<int> d(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    if(k == 0) {
        cout << A[0] << '\n';
        return;
    }

    int root = 0;

    vector<int> p(n, -1);
    vector<int> vis(n, 0);

    int timer = 0;
    int node = root;
    function<void(int, int)> build = [&](int u, int par) {
        if(vis[u])  {
            return;
        }
        if(d[u] > d[node]) {
            node = u;
        }
        for(auto& v: g[u]) {
            if(v != par) {
                p[v] = u;
                d[v] = d[u] + A[v];
                build(v, u);
            }
        }
    };
    
    d[root] = A[root];
    build(root, -1);
    int ans = d[node];
    
    while(node > 0) {
        A[node] = 0;
        vis[node] = 1;
        node = p[node];
    }
    A[root] = 0;
        
    node = 0;
    d[root] = A[root];
    build(root, -1);
    ans += d[node];

    cout << ans << '\n';
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