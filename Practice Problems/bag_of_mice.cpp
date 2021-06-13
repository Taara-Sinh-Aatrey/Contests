/**
 *    author:  Taara Sinh Aatrey
 *    created: 08.06.2021 14:31:44
**/

#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, const pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
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
    
    cout << fixed << setprecision(12);

    int A, B;
    cin >> A >> B;
        
    vector<vector<long double>> dp(A + 1, vector<long double>(B + 1, 0));

    dp[A][B] = 1;

    for(int a = A; a >= 0; a--) {
        for(int b = B; b >= 2; b--) {
            long double p = dp[a][b];
            p = p * b / (a + b);
            p = p * (b - 1) / (a + b - 1);
            if(a >= 1) {
                dp[a - 1][b - 2] += p * a / (a + b - 2);
            }
            if(b >= 3) {
                dp[a][b - 3] += p * (b - 2) / (a + b - 2);
            }
        }
    }

    long double ans = 0;

    for(int a = 1; a <= A; a++) {
        for(int b = 0; b <= B; b++) {
            ans += dp[a][b] * a / (a + b);
        }
    }
    cout << ans;

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

