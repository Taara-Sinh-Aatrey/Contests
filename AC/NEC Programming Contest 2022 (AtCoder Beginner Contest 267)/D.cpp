/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2022 18:09:15
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    const int inf = 1e18L + 5;
    vector<int> dp(m + 1, -inf);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto ndp = dp;
        for (int j = 1; j <= m; j++) {
            ndp[j] = max(ndp[j], dp[j - 1] + x * j);
        }
        swap(dp, ndp);
    }
    cout << dp[m];
    return 0;
}