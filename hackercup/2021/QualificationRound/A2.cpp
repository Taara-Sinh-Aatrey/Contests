/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2021 22:44:41
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

void solve() {
    
    string s;
    cin >> s;
    
    int n = s.size();
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = s[i] - 'A';
    }
    
    int m;
    cin >> m;
    vector<vector<int>> g(26, vector<int>(26, 1e9));
    for(int i = 0; i < m; i++) {
        char x, y;
        cin >> x >> y;
        int u = x - 'A', v = y - 'A';
        g[u][v] = 1;
    }
    
    for(int i = 0; i < 26; i++) {
        g[i][i] = 0;
    }
    
    for(int k = 0; k < 26; k++) {
        for(int i = 0; i < 26; i++)  {
            for(int j = 0; j < 26; j++) {
                amin(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    
    int ans = INF;
    for(int x = 0; x < 26; x++) {
        int cur = 0;
        for(auto& y : a) {
            cur += g[y][x];
        }
        amin(ans, cur);
    }
    
    if(ans >= 1e9) ans = -1;
    
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    
    return 0;
}