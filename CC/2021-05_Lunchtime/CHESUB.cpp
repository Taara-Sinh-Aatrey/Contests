/**
 *    author:  Taara Sinh Aatrey
 *    created: 31.05.2021 20:12:07
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
    if (b > a) a = b;
    return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
    if (b < a) a = b;
    return a;
}

const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 2e5 + 5;

void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    cin >> a;
    a.insert(a.begin(), 0);


    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(k + 1, make_pair(-INF, -INF)));
    // dp[i][j].first -> [0, i] with j partiton, gap is there, we skipped ith element
    // dp[i][j].second -> [0, i] with j partition, no gap, we took ith element
    // gap, no gap
    dp[0][0].first = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {

            // gap -> gap continued
            amax(dp[i + 1][j].first, dp[i][j].first);

            // no gap -> gap created
            amax(dp[i + 1][j].first, dp[i][j].second);
            
            // no gap -> no gap (old partition)
            amax(dp[i + 1][j].second, dp[i][j].second + a[i + 1] * j);
            
            if(j + 1 <= k) {
                // gap -> no gap (new partition)
                amax(dp[i + 1][j + 1].second, dp[i][j].first + a[i + 1] * (j + 1));

                // no gap -> no gap (new partition)
                amax(dp[i + 1][j + 1].second, dp[i][j].second + a[i + 1] * (j + 1));
                
            }
        }
    }

    cout << max(dp[n][k].first, dp[n][k].second) << '\n';
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