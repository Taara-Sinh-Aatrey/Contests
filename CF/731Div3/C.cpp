/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.07.2021 20:17:41
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
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<int> a(n), b(m);
    cin >> a >> b;
    
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(m + 1, make_pair(0, 0)));
    vector<vector<pair<int, int>>> last(n + 1, vector<pair<int, int>>(m + 1, make_pair(-1, -1)));
    dp[0][0] = {1, k};
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(dp[i][j].first == 0) {
                continue;
            }
            // dbg(dp[i][j]);
            if(i + 1 <= n && a[i + 1] <= dp[i][j].second) {
                dp[i + 1][j] = {1, dp[i][j].second + (a[i + 1] == 0)};
                last[i + 1][j] = {i, j};
                // dbg(dp[i + 1][j]);
            }
            if(j + 1 <= m && b[j + 1] <= dp[i][j].second) {
                dp[i][j + 1] = {1, dp[i][j].second + (b[j + 1] == 0)};
                last[i][j + 1] = {i, j};
                // dbg(dp[i][j + 1]);
            }
        }
    }
    if(!dp[n][m].first) {
        cout << -1 << '\n';
        return;
    }
    
    pair<int, int> i = {n, m};
    vector<int> ans;
    while(i != make_pair(int(0), int(0))) {
        pair<int, int> j = last[i.first][i.second];
        if(i.first != j.first) {
            ans.emplace_back(a[i.first]);
        }
        else {
            ans.emplace_back(b[i.second]);
        }
        i = j;
    }
    reverse(ans.begin(), ans.end());
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