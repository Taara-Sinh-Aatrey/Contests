#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, m, k;
    scan(n, m, k);
    vector<array<int, 3>> a(k);
    scan(a);
    vector<vector<int>> row(n), col(m);
    for (int i = 0; i < k; i++) {
        auto &[r, c, w] = a[i];
        --r, --c;
        row[r].emplace_back(i);
        col[c].emplace_back(i);
    }
    vector<vector<int>> g(k);
    auto comp = [&] (auto &i, auto &j) {
        return a[i][2] < a[j][2];
    };
    auto create_graph = [&] (vector<int> &v) {
        sort(v.begin(), v.end(), comp);
        for (int i = 1; i < v.size(); i++)
            g[v[i - 1]].emplace_back(v[i]);       
        for (int i = 0, j; i < v.size(); i = j) {
            j = i;
            while (j < v.size() && a[v[j]][2] == a[v[i]][2]) 
                j++;
            if (j >= v.size()) 
                break;
            for (int x = i; x < j - 1; x++)
                g[v[x]].emplace_back(v[j]);
        }
    };
    for (int it = 0; it < n; it++)
        create_graph(row[it]);
    for (int it = 0; it < m; it++)
        create_graph(col[it]);
    vector<int> topo_order;
    vector<int> vis(k);
    function<void(int)> Dfs = [&](int u) -> void {
        vis[u] = true;
        for (auto& v : g[u]) {
            if(vis[v]) continue;
            Dfs(v);
        }
        topo_order.emplace_back(u);
    };
    for(int u = 0; u < k; u++) {
        if(vis[u]) continue;
        Dfs(u);
    }
    vector<int> ans(k), saveR(k), saveC(k);
    for (auto &u : topo_order) {
        for (auto &v : g[u]) {
            if (a[u][2] != a[v][2]) {
                    amax(ans[u], saveR[v] + 1);
                    amax(ans[u], saveC[v] + 1);
                    amax(saveR[u], ans[u]);
                    amax(saveC[u], ans[u]);
            }
            else {
                if (a[u][0] == a[v][0])
                    amax(saveR[u], saveR[v]);
                else
                    amax(saveC[u], saveC[v]);
            }
        }
    }
    for (auto &x : ans) print(x);
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