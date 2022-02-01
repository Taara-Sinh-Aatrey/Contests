#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 1e3 + 5;

vector<int> ops(N, inf);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (auto &x : b) {
        cin >> x; 
        x = ops[x];
    }
    for (auto &x : c)
        cin >> x;
    k = min(k, n * 12);
    vector<int> dp(k + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = k - b[i]; j >= 0; j--) {
            dp[j + b[i]] = max(dp[j + b[i]], dp[j] + c[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ops[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j < N)
                ops[i + i / j] = min(ops[i + i / j], ops[i] + 1);
        }
    }
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}