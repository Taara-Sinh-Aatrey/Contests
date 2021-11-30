#include "bits/stdc++.h"
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

// helper functions
namespace tsa {
    // most significant bit
    int msb (int64_t x) {
        return 63 - __builtin_clzll(x);
    }
    
    // least significant bit
    int lsb (int64_t x) {
        return __builtin_ctzll(x);
    }
    
    // extracts the last element
    template <typename T>
    T extract_back (vector<T> &v) {
        T x = v.back();
        v.pop_back();
        return x;    
    };
    
    // in-place co-ordinate compression, returns no of unique elements
    template<typename T>
    T compress (vector<T> &a, int offset = 0) {
        vector<T> b = a;
        sort(b.begin(), b.end());
        b.resize(b.end() - unique(b.begin(), b.end()));
        for(T &x : a)
            x = lower_bound(b.begin(), b.end(), x) - b.begin() + offset;
        return b.size();
    }
}

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> d(n);
    vector<int> sz(2);
    function<void(int, int)> dfs = [&](int u, int par) {
        d[u] = par == -1 ? 0 : d[par] + 1;
        sz[d[u] & 1]++;
        for(auto& v : g[u]) {
            if(v == par) continue;
            dfs(v, u);
        }    
    };
    dfs(0, -1);
    int idx = min_element(sz.begin(), sz.end()) - sz.begin();
    vector<int> v[2];
    for (int i = 1; i <= n; i++) {
        if (sz[idx] >> tsa::msb(i) & 1)
            v[1].emplace_back(i);
        else
            v[0].emplace_back(i);
    }
    for (int u = 0; u < n; u++)
        cout << tsa::extract_back(v[d[u] % 2 == idx]) << " \n"[u == n - 1];
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