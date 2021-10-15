/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.08.2021 18:13:00
**/

#include <algorithm>
#include <bits/c++config.h>
#include <bits/stdc++.h>
#include <numeric>
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
const int mod = 998244353; const int INF = 1e18L + 5;

void solve() {
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](const int& i, const int& j) {
        return a[i] < a[j];
    });
    
    auto add = [&](int& x, int y) {
        x += y;
        if(x >= mod) x -= mod;
    };
    auto sub = [&](int& x, int y) {
        x -= y;
        if(x < 0) x += mod;
    };
    
    const int N = 1 + *max_element(a.begin(), a.end());
    vector<int> dp(N, 0);
    dp[0] = 1;
    auto pref = dp;
    for(int j = 1; j < N; j++) {
        add(pref[j], pref[j - 1]);
    }
    int ans = 0;
    
    for(int it = 0, jt = 0; it < n; it = jt) {
        jt = it;
        while(jt < n && a[order[it]] == a[order[jt]]) {
            for(int sum = N - 1; sum >= b[order[jt]]; sum--) {
                add(dp[sum], dp[sum - b[order[jt]]]);
            }
            jt++;
        }
        sub(ans, pref[a[order[it]]]);
        pref = dp;
        for(int j = 1; j < N; j++) {
            add(pref[j], pref[j - 1]);
        }
        add(ans, pref[a[order[it]]]);
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