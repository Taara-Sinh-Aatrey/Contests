/**
 *    author:  Taara Sinh Aatrey
 *    created: 08.06.2021 20:32:27
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
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
    if(b > a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amax(a, c...);
    }
    return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
    if(b < a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amin(a, c...);
    }
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;
const int lvl = 19;


void solve() {

    int n, q;
    cin >> n >> q;

    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<vector<int>> p(lvl, vector<int>(n, -1));
    vector<int> depth(n, 0);
    vector<int> down_sum(n, 0);
    vector<int> top_sum(n, 0);
    vector<int> sz(n, 1);

    function<void(int, int)> dfs = [&](int u, int par) {
        for(auto& v: g[u]) {
            if(v != par) {
                p[0][v] = u;
                depth[v] = depth[u] + 1;
                dfs(v, u);
                down_sum[u] += down_sum[v] + sz[v];
                sz[u] += sz[v];
            }
        }
    };

    function<void(int, int)> dfs2 = [&](int u, int par) {
        for(auto& v: g[u]) {
            if(v != par) {
                top_sum[v] += top_sum[u] + n - sz[v] + down_sum[u] - (down_sum[v] + sz[v]);
                dfs2(v, u);
            }
        }
    };

    dfs(0, -1);
    dfs2(0, -1);
    // cerr << down_sum << endl << top_sum << endl;


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

    while(q--) {
        int a, b;
        cin >> a >> b, --a, --b;

        if(depth[a] > depth[b]) {
            swap(a, b);
        }

        int lca = find_lca(a, b);
        int d = depth[a] + depth[b] - 2 * depth[lca]; 
        int db = (d - 1) / 2;
        int da = d - db;
        int c = get(b, db);

        int ans = 0;

        if(lca != a) {
            ans += down_sum[a] + top_sum[a] - (down_sum[c] + da * sz[c]);
            ans += down_sum[b] + top_sum[b] - (top_sum[c] + (n - sz[c]) * db);
        }
        else {
            ans = down_sum[b] + top_sum[a];
            ans += down_sum[a] - (down_sum[c] + sz[c] * da);
            ans += top_sum[b] - (top_sum[c] + (n - sz[c]) * db);
        }

        cout << ans << '\n';

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