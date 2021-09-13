#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u][v] = 1;
        edges[i] = {u, v};
    }
    
    vector<pair<int, int>> s;
    vector<pair<int, int>> d;
    
    auto bfs = [&](int src, bool save, bool rev) {
        vector<pair<int, int>> dis(n, pair(inf, 0));
        dis[src] = {0, 1};
        queue<int> q;
        q.emplace(src);
        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            for(int v = 0; v < n; v++) {
                if(g[rev?v:u][rev?u:v] && dis[v].first > dis[u].first + 1) {
                    q.emplace(v);
                    dis[v] = {dis[u].first + 1, dis[u].second};
                }
                else if(g[rev?v:u][rev?u:v] && dis[v].first == dis[u].first + 1) {
                    dis[v].second += dis[u].second;
                }
            }
        }
        if(save) {
            if(rev) d = dis;
            else s = dis;
        }
        return (dis[n - 1].first >= inf ? -1 : dis[n - 1].first);
    };
    
    bfs(0, true, false);
    bfs(n - 1, true, true);
    
    assert(s[n - 1] == d[0]);
    int mn = d[0].first;
    
    for(auto& [u, v] : edges) {
        if(mn >= inf) {
            cout << -1 << '\n';
        }
        else {
            int cur = s[u].first + d[v].first + 1;
            int ways = s[u].second * d[v].second;
            if(cur > mn || ways < d[0].second) {
                cout << mn << '\n';
            }
            else {
                g[u][v] = 0;
                cout << bfs(0, false, false) << '\n';
                g[u][v] = 1;
            }
        }
    }
    
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }

    return 0;
}