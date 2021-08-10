/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.08.2021 09:01:43
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

int Pow(int a, int b, int P = mod){
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void solve() {
    
    auto add = [&](int& a, int b) {
        a += b;
        if(a >= mod) {
            a -= mod;
        }  
    };
    
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    a.insert(a.begin(), 0);
    
    int lim = min<int>(n, 54);
    
    vector<vector<int>> dp(n + 1, vector<int>(lim + 1, int(0)));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= lim; j++) {
            int Xor = 0;
            for(int k = i; k >= 1; k--) {
                Xor ^= a[k];
                if(Xor == 0 || __builtin_ctz(Xor) >= j - 1) {
                    add(dp[i][j], dp[k - 1][j - 1]);
                }
            }
        }
    }
    
    int ans = 0;
    for(int j = 1; j <= lim; j++) {
        add(ans, dp[n][j]);
    }
    
    int Xor = 0;
    int cnt = 0;
    for(int i = n; i >= 1; i--) {
        Xor ^= a[i];
        if(Xor == 0) {
            add(ans, dp[i - 1][lim] * Pow(2, cnt) % mod);
            cnt++;
        }
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