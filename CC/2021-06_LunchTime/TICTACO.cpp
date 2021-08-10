/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.06.2021 23:40:07
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
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for(int i = 0; i < n * m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = i;
    }
    
    auto check = [&](int mid) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int p : {0, 1}) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    dp[i][j] = (a[i][j] <= mid && a[i][j] % 2 == p) + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                    if(i >= k && j >= k && dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] == k * k) {
                        return p;
                    }
                }
            }  
        }
        return int(-1);
    };
    
    int low = 0, high = n * m - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid) >= 0) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    int ans = check(low);
    
    cout << (ans == -1 ? "Draw" : (ans == 0 ? "Alice" : "Bob")) << '\n';
    
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