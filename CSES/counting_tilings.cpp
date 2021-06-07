/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.05.2021 21:08:05
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(m + 1, vector<int>(1 << n));

    dp[0][0] = 1;
    for(int c = 0; c < m; c++) {
        for(int mask = 0; mask < (1 << n); mask++) {
            vector<int> vec;
            for(int r = 0; r < n; r++) {
                if(mask >> r & 1) continue;
                vec.emplace_back(r);
            }
            int sz = int(vec.size());
            function<void(int, int)> dfs = [&](int i, int cur_mask) {
                if(i >= sz) {
                    dp[c + 1][cur_mask] += dp[c][mask];
                    if(dp[c + 1][cur_mask] >= mod) {
                        dp[c + 1][cur_mask] -= mod;
                    }
                    return;
                }
                dfs(i + 1, cur_mask | (1 << vec[i]));
                if(i + 1 < sz && vec[i] + 1 == vec[i + 1]) {
                    dfs(i + 2, cur_mask);
                }
            };
            dfs(0, 0);
        }
    }

    cout << dp[m][0] % mod;


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
