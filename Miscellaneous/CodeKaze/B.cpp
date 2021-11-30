#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    string l, r;
    scan(l, r);
    vector<int> sq(901);
    for (int i = 0; i * i <= 900; i++)
        sq[i * i] = 1;
    auto fun = [&] (string s) {
        vector<int> dp(901, 0);
        int n = s.size();
        int eqsum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> ndp(901);
            int D = s[i] - '0';
            for (int d = 0; d <= 9; d++) {
                for (int sum = 0; sum + d <= 900; sum++) {
                    ndp[sum + d] += dp[sum]; 
                    ndp[sum + d] %= mod; 
                }
            }
            for (int d = 0; d < D; d++) {
                ndp[eqsum + d]++;
                ndp[eqsum + d] %= mod; 
            }
            eqsum += D; 
            swap(dp, ndp);
        }
        int ans = 0;
        for (int sum = 0; sum <= 900; sum++) {
            if (sq[sum]) {
                ans += dp[sum];
                ans %= mod;
            }
        }
        if (sq[eqsum]) {
            ans++;
            ans %= mod;
        }
        return ans;  
    };
    int sum_l = 0;
    for (auto &ch : l) {
        sum_l += ch - '0';
    }
    int ans = fun(r) - fun(l) + sq[sum_l];
    ans = (ans + mod) % mod;
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}