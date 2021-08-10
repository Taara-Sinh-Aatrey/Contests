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
    
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> a(n);
    cin >> a;
    a.emplace_back(INF);
    
    const int lvl = 19;
    
    vector<vector<int>> nxt(lvl, vector<int>(n + 1));
    
    int j = n;
    int cur = INF;
    nxt[0][n] = n;
    
    for(int i = n - 1; i >= 0; i--) {
        cur += a[i];
        while(cur > s) {
            cur -= a[j];
            j--;
        }
        nxt[0][i] = j + 1;
    }
    
    for(int j = 1; j < lvl; j++) {
        for(int i = 0; i <= n; i++) {
            nxt[j][i] = nxt[j - 1][nxt[j - 1][i]];
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        for(int b = 0; b < lvl; b++) {
            if(k >> b & 1) {
                j = nxt[b][j];
            }
        }
        amax(ans, j - i);
    }
    
    cout << ans << '\n';
        
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

/*

[j - i, i, j]: 7 0 7
[j - i, i, j]: 8 1 9
[j - i, i, j]: 7 2 9
[j - i, i, j]: 7 3 10
[j - i, i, j]: 6 4 10
[j - i, i, j]: 5 5 10
[j - i, i, j]: 4 6 10
[j - i, i, j]: 3 7 10
[j - i, i, j]: 2 8 10
[j - i, i, j]: 1 9 10
*/


    