// #include "bits/stdc++.h"
// using namespace std;

// template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
// template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
// void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
// void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
// template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

// #ifdef LOCAL
// #include "debug.hpp"
// #else
// #define dbg(...)
// #endif

// #define int int64_t
// const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

// int n;
// vector<map<int, int>> capacity;
// vector<vector<int>> adj;
// vector<vector<int>> paths;

// int bfs(int s, int t, vector<int>& parent) {
//     fill(parent.begin(), parent.end(), -1);
//     parent[s] = -2;
//     queue<pair<int, int>> q;
//     q.push({s, inf});

//     while (!q.empty()) {
//         int cur = q.front().first;
//         int flow = q.front().second;
//         q.pop();

//         for (int next : adj[cur]) {
//             if (parent[next] == -1 && capacity[cur][next]) {
//                 parent[next] = cur;
//                 int new_flow = min(flow, capacity[cur][next]);
//                 if (next == t)
//                     return new_flow;
//                 q.push({next, new_flow});
//             }
//         }
//     }

//     return 0;
// }

// int maxflow(int s, int t) {
//     int flow = 0;
//     vector<int> parent(n);
//     int new_flow;

//     while (flow < 2 && (new_flow = bfs(s, t, parent)) > 0) {
//         flow += new_flow;
//         int cur = t;
//         while (cur != s) {
//             int prev = parent[cur];
//             capacity[prev][cur] -= new_flow;
//             capacity[cur][prev] += new_flow;
//             cur = prev;
//         }
//     }

//     return flow;
// }

// void solve() {
//     int m, s;
//     scan(n, m, s);
//     adj = vector<vector<int>>(n);
//     capacity = vector<map<int, int>>(n);
//     while (m--) {
//         int u, v;
//         scan(u, v), --u, --v;
//         adj[u].emplace_back(v);
//         capacity[u][v] = 1;
//     }
// }

// signed main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     for (int tt = 1; tt <= t; tt++) {
//         solve();
//     }
//     return 0;
// }

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

void solve() {
    int n, m, s;
    scan(n, m, s), --s;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        scan(u, v), --u, --v;
        g[u].emplace_back(v);
    }
    vector<int> vis(n, 0), par(n, -1);
    int cur = 0;
    function<void(int, int)> dfs = [&] (int u, int parent) {
        if (vis[u] > 0) {
            cout << "Possible\n";
            vector<int> path;
            int node = u;
            while (node >= 0) {
                path.emplace_back(node);
                node = par[node];
            }
            reverse(path.begin(), path.end());
            print(path.size());
            for (auto &x : path) {
                x++;
            }
            print(path);
            path = {u};
            node = parent;
            while (node >= 0) {
                path.emplace_back(node);
                node = par[node];
            }
            reverse(path.begin(), path.end());
            print(path.size());
            for (auto &x : path) {
                x++;
            }
            print(path);
            exit(0);
        }
        vis[u] = cur;
        par[u] = parent;
        for(auto& v : g[u]) {
            if(vis[v] == cur || v == s) {
                continue;
            }
            dfs(v, u);
        }
    };
    for (auto &v : g[s]) {
        cur++;
        dfs(v, s);
    }
    cout << "Impossible\n";
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