/**
 *    author:  Taara Sinh Aatrey
 *    created: 19.05.2021 11:27:16
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
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> deg(n);
    vector<set<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
        deg[u]++;
        deg[v]++;
    }

    for(int u = 0; u < n; u++) {
        if(deg[u] & 1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    vector<int> ans;

    function<void(int)> dfs = [&](int u) {
        while(!g[u].empty()) {
            auto v = *g[u].begin();
            g[u].erase(v);
            g[v].erase(u);
            dfs(v);
            ans.emplace_back(u);
        }
    };

    ans.emplace_back(0);
    dfs(0);

    if(int(ans.size()) <= m) {
        cout << "IMPOSSIBLE";
        return;
    }

    for(int& u: ans) {
        cout << u+1 << " ";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}