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

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> adj(N, 0);
    vector<int> L(N), R(N), A(N);

    for (int i = 0; i < N; i++)
        cin >> L[i] >> R[i] >> A[i];

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        adj[x] |= 1 << y;
        adj[y] |= 1 << x;
    }

    vector<int64_t> dp(1 << N, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++)
        dp[1 << i] = 1;

    int64_t ans = 0;

    for (int mask = 0; mask < 1 << N; mask++) {
        int reach = 0, points = 0;

        for (int i = 0; i < N; i++)
            if (mask >> i & 1) {
                reach |= adj[i];
                points += A[i];
            }

        for (int i = 0; i < N; i++)
            if ((mask >> i & 1) == 0 && (reach >> i & 1) && L[i] <= points && points <= R[i])
                dp[mask | 1 << i] += dp[mask];

        if (points == K)
            ans += dp[mask];
    }
    cout << ans << '\n';
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