/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.12.2022 20:53:04
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
    int n, k, d;
    cin >> n >> k >> d;
    const int inf = 1e18L + 5;
    vector<vector<int>> dp(k + 1, vector<int>(d, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int taken = k - 1; taken >= 0; taken--) {
            for (int r = 0; r < d; r++) {
                dp[taken + 1][(r + x) % d] = max(dp[taken + 1][(r + x) % d], dp[taken][r] + x);
            }
        }
    }
    cout << (dp[k][0] < 0 ? -1 : dp[k][0]);
    return 0;
}