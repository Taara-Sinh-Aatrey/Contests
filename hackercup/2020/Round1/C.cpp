/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2021 12:57:28
**/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
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

void solve(int tt) {
    
    int n, k;
    cin >> n >> k;
    // dbg(n);
    string s;
    cin >> s;
    vector<int> p(k);
    cin >> p;
    p.insert(p.begin(), 0);
    {
        int x, y, z;
        cin >> x >> y >> z;
        for(int i = k + 1; i < n; i++) {
            p.emplace_back((p[i - 2] * x + p[i - 1] * y + z) % i + 1);            
        }
        for(auto& par : p) {
            --par;
        }
    }
    
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        g[p[i]].emplace_back(i);
    }
    
    map<int, int, greater<int>> mp;
    
    int extra = 0;
    int pairs = 0;
    
    vector<int> cnt(n), sz(n);
    function<void(int)> dfs = [&](int u) {
        sz[u]++;
        cnt[u]++;
        for(auto& v : g[u]) {
            dfs(v);
            if(s[u] == '#' || s[v] == '#') {
                extra += sz[v] * (n - sz[v]);
            }
            cnt[u] += cnt[v];
            sz[u] += sz[v];
        }
        if(s[u] == '*') {
            if(p[u] == -1 || s[p[u]] == '#') {
                mp[cnt[u]]++;
                pairs += cnt[u] * (cnt[u] - 1) / 2;
            }
        }
        else {
            cnt[u] = 0;
        }
    };
    dfs(0);
    if(tt == 46) dbg(mp);
    
    if(mp.empty()) {
        // cerr << 1 << " ";
        cout << 0 << " " << extra << '\n';
    }
    else if(mp.begin()->second > 1) {
        // cerr << 2 << " ";
        auto [c, f] = *mp.begin();
        pairs -= c * (c - 1);
        pairs += 2 * c * (2 * c - 1) / 2;
        cout << pairs << " " << f * (f - 1) * c * c << '\n';
    }
    else if(mp.size() == 1) {
        // cerr << 3 << " ";
        auto [c, f] = *mp.begin();
        int ans = extra;
        function<void(int)> Dfs = [&](int u) {
            for(auto& v : g[u]) {
                if(s[u] == '*' && s[v]== '*') {
                    ans += cnt[v] * (c - cnt[v]);
                }
                Dfs(v);
            }
        };
        Dfs(0);
        cout << c * (c - 1) / 2 << " " << ans << '\n';
    }
    else {
        // cerr << 4 << " ";
        auto [c1, f1] = *mp.begin();
        auto [c2, f2] = *next(mp.begin());
        pairs -= c1 * (c1 - 1) / 2;
        pairs -= c2 * (c2 - 1) / 2;
        pairs += (c1 + c2) * (c1 + c2 - 1) / 2;
        cout << pairs << " " << f2 * 2 * c1 * c2 << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve(tt);
    }
    
    return 0;
}

