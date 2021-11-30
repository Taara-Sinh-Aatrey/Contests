#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
    if(b > a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amax(a, c...);
    }
    return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
    if(b < a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amin(a, c...);
    }
    return a;
}

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, m, k;
    scan(n, m, k);
    vector<string> s(m, string(n, '?'));
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scan(s[j][i]);
        }
    }
    vector<int> L(k);
    scan(L);
    vector<int> ans(n * m + 1, inf);
    for (int rep = 0; rep < 2; rep++) {
        char ch = "AB"[rep];
        int rem = n * m;
        vector<int> p(m);
        bool consider = true;
        vector<int> vec;
        while(rem > 0) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                while(p[i] < n && s[i][p[i]] == ch) {
                    cnt++;
                    p[i]++;                
                }
            }
            if(cnt == 0) { 
                consider = false;
                break;
            }
            // dbg(rep, rem);
            rem -= cnt;
            vec.emplace_back(cnt);
            ch ^= 'A' ^ 'B';
        }
        if(!consider) continue;
        dbg(rep, vec);
        vector<vector<int>> dp(n * m + 1, vector<int>(2, inf));
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            int me = i % 2;
            vector<vector<int>> ndp(n * m + 1, vector<int>(2, inf));
            for (int deleted = 0; deleted < cnt; deleted++) {
                for (int you : {0, 1}) {
                    if(me == you) {
                       amin(ndp[deleted][me], dp[deleted][you]);
                    }
                    else {
                       amin(ndp[deleted + vec[i]][you], dp[deleted][you]);
                       amin(ndp[deleted][me], dp[deleted][you] + 1);
                    }
                }
            }
            dp = ndp;
            dp[cnt][me] = 1;
            cnt += vec[i];
            dp[cnt][0] = 0;
            dp[cnt][1] = 0;
            for (int deleted = 1; deleted <= cnt; deleted++) {
                for (int you : {0, 1}) {
                    amin(dp[deleted][you], dp[deleted - 1][you]);
                }
            }
            // dbg(vec);
            // dbg(i, vec[i], dp);
        }
        // dbg(dp);
        for (int deleted = 0; deleted <= n * m; deleted++) {
            amin(ans[deleted], dp[deleted][0], dp[deleted][1], (deleted > 0 ? ans[deleted - 1] : inf));
        }
    }
    for (auto& deleted : L) {
        cout << ans[deleted] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}