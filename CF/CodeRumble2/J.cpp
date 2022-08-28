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
    int n, root;
    scan(n, root), --root;
    vector<string> s(n);
    scan(s);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        int sz;
        scan(sz);
        g[i].resize(sz);
        scan(g[i]);
        for (auto &x : g[i]) {
            --x;
        }
    }
    vector<int> vis(n), act(n);
    function<void(int, int)> dfs = [&] (int u, int val) {
        vis[u] = val;
        act[u] = 1;
        for(auto& v : g[u]) {
            if(vis[v] == 2) {
                continue;
            }
            if (act[v]) {
                dfs(v, 2);
            }
            else if (val > vis[v]) {
                dfs(v, val);
            }
        }
        act[u] = 0;
    };
    dfs(root, 1);
    for (int i = 0; i < n; i++) {
        if (vis[i] == 2) {
            cout << s[i] << " ";
        }
    }
    if (*max_element(vis.begin(), vis.end()) < 2) {
        cout << "Safe chain email!";
    }
    print();
    print();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Chain Email #" << tt << ":\n";
        solve();
    }
    return 0;
}