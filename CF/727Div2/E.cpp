/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.06.2021 16:39:35
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
    int n, m;
    cin >> n >> m;
    
    map<int, array<int, 5>> dp[n + 1];
    dp[0][0] = {0, 0, 1, 1, -1};
    
    auto inter = [&](int a, int b, int c, int d, array<int, 2>& res) {
        res[0] = max(a, c);
        res[1] = min(b, d);
        return res[0] <= res[1];
    };
    
    for(int it = 1; it <= n; it++) {
        int r;
        cin >> r;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        for(auto [i, ar]: dp[it - 1]) {
            
            // replace left
            array<int, 2> res;
            if(inter(r, r, a, b, res) && inter(ar[2], ar[3], c, d, res)) {
                dp[it][0] = {r, r, res[0], res[1], i}; 
            }
            
            // replace right
            if(inter(r, r, c, d, res) && inter(ar[0], ar[1], a, b, res)) {
                dp[it][1] = {res[0], res[1], r, r, i}; 
            }
        }
        
        // dbg(it, dp[it]);
                
        if(dp[it].empty()) {
            cout << "No";
            return;
        }
    }
    
    cout << "Yes" << '\n';
    vector<int> ans(n + 1);
    for(auto [b, ar] : dp[n]) {
        ans[n] = b;
        break;
    }
    
    for(int i = n - 1; i >= 1; i--) {
        ans[i] = dp[i + 1][ans[i + 1]][4];
    }
    
    ans.erase(ans.begin());
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