/**
 *    author:  Taara Sinh Aatrey
 *    created: 30.04.2021 20:33:21
**/

// #undef _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string) s); }

string to_string(const char& ch) { return "'" + string(1, ch) + "'"; }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

#define int int64_t
#define ar array<int, 2>
#define pii pair<int, int>
#define pb push_back
#define vt vector
#define For(i, n) for (int i = 0; i < n; i++)
#define Rev(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, n) for (int i = 1; i <= n; i++)
#define REV(i, n) for (int i = n; i >= 1; i--)
#define Rep(i, a, b) for (int i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define msb(x) (int) (31 - __builtin_clz(x))
#define lsb(x) __builtin_ctz(x)
template <typename T>
using mxpq = priority_queue<T>;
template <typename T>
using mnpq = priority_queue<T, vt<T>, greater<T>>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

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
istream& operator>>(istream& in, vt<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vt<T>& a) {
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
const int lvl = 20;

int depth[N];
bool vis[N];
vt<vt<int>> g;
pair<int, pii> p[lvl][N];
int n;

void dfs(int u, int par){
    depth[u] = par != -1 ? 1 + depth[par] : 0;
    bool ok = vis[u];
    for(int v: g[u]){
        if(v != par){
            dfs(v, u);
            ok = ok | (p[0][v].second.first != INF);
        }
    }
    p[0][u] = {max<int>(par, 0), {ok ? depth[u] : INF, ok ? depth[u] : -INF}};
}

void compute_parent(){
    for(int i = 1; i < lvl; i++){
        For(node, n){
            int x = p[i - 1][node].first;
            p[i][node].first = p[i - 1][x].first;
            p[i][node].second.first = min(p[i - 1][node].second.first, p[i - 1][x].second.first); 
            p[i][node].second.first = max(p[i - 1][node].second.second, p[i - 1][x].second.second); 
        }
    }
}

pair<int, pii> find_lca(int u, int v){
    dbg(u, v);
    dbg(depth[u], depth[v]);
    pair<int, pii> ret = {-1, {INF, -INF}};
    int &mn = ret.second.first, &mx = ret.second.second;

    int diff = abs(depth[v] - depth[u]);
    if(depth[v] > depth[u]) {
        for (int i = lvl - 1; i >= 0; i--)
            if (diff >= (1 << i)) {
                diff -= (1 << i);
                amin(mn, p[i][v].second.first);
                v = p[i][v].first;
            }
    } else if(depth[v] < depth[u]) {
        for (int i = lvl - 1; i >= 0; i--)
            if (diff >= (1 << i)) {
                diff -= (1 << i);
                amax(mx, p[i][u].second.second);
                u = p[i][u].first;
            }
    }
    dbg(u, v);
    dbg(depth[u], depth[v]);

    if (u == v) {
        ret.first = u;
        return ret;
    }

    for (int i = lvl - 1; i >= 0; i--){
        if (p[i][u].first != p[i][v].first){
            amax(mx, p[i][u].second.second);
            amin(mn, p[i][v].second.first);
            u = p[i][u].first;
            v = p[i][v].first;
        }
    }
    ret.first = p[0][u].first;
    amax(mx, p[0][u].second.second);
    amin(mn, p[0][v].second.first);
    return ret;
}

void solve() {
    for(int i = 0; i < lvl; i++) {
        for(int j = 0; j < N; j++) {
            vis[j] = 0;
            p[i][j] = {0, {INF, -INF}};
        }
    }
    int k, a;
    cin >> n >> k >> a;
    a--;
    g = vt<vt<int>>(n);

    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        vis[x] = 1;
    }

    bool ok = true;

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if(u != i || v != i + 1) {
            ok = false;
        }
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);
    compute_parent();

    vector<pii> ans(n, {-INF, -INF});

    for(int i = 0; i < n; i++) {
        auto [lca, x] = find_lca(a, i);
        auto [mn, mx] = x;

        int d = depth[a] + depth[i] - 2 * depth[lca];
        int best = 2 * min(mn - depth[i], depth[lca] - mx + depth[lca] - depth[i]);
        int ans = d - best;
        cout << ans << " ";
    }
    for(auto& [f, s]: ans) {
        cout << f << " ";
    }
    cout << '\n';

    for(auto& [f, s]: ans) {
        cout << s + 1 << " ";
    }
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        // cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}
