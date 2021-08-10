/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.06.2021 20:05:26
**/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, const pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
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
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> diff(n);
    cin >> diff;
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int& i, const int& j) {
        return diff[i] < diff[j];
    });
    
    vector<int> idx(n);
    for(int i = 0; i < n; i++) {
        idx[order[i]] = i;
    }
        
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u = idx[u];
        v = idx[v];
        if(u < v) {
            swap(u, v);
        }
        g[u].emplace_back(w, v);
    }
    
    // map<int, vector<pair<int, int>>> Q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l = idx[l];
        r = idx[r];
        vector<int> d(n, INF);
        d[l] = 0;
        for(int u = l; u > r; u--) {
            for(auto [w, v] : g[u]) {
                amin(d[v], d[u] + w);
            }
        }
        if(d[r] >= INF) d[r] = -1;
        cout << d[r] << '\n';
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