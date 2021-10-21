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
    vector<vector<int>> g(n);
    vector<int> d(n);
    {
        set<pair<int, int>> st;
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v, --u, --v;
            if (u > v) {
                swap(u, v);
            }
            if (st.count({u, v})) continue;
            st.emplace(u, v);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            d[u]++;
            d[v]++;
        }
    }
    vector<int> timer(n);
    int time = n - 1;
    vector<bool> vis(n);
    set<array<int, 3>> st;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for(auto& v : g[u]) {
            if(vis[v]) continue;
            dfs(v);
        }
        timer[u] = time--;
        st.insert({d[u], timer[u], u});
    };
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
    vector<int> a(n, -1);
    int cur = n;
    while(!st.empty()) {
        auto [du, tu, u] = *st.begin();
        st.erase(st.begin());
        a[u] = cur--;
        for (auto& v : g[u]) {
            if (~a[v]) continue;
            st.erase({d[v], timer[v], v});
            d[v]--;
            st.insert({d[v], timer[v], v});
        }
    }
    int mx = 0;
    for (int u = 0; u < n; u++) {
        int score = 0;
        for (auto& v : g[u]) {
            score += a[v] < a[u];
        }
        mx = max(mx, score);
    }
    print(mx);
    print(a);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}
    