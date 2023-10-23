/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 17:45:21
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
    int n;
    cin >> n;
    const int inf = 1e18L + 5;
    vector<int> dp(5, -inf);
    dp[0] = 0;
    int pt = 0;
    for (int i = 0; i < n; i++) {
        int t, x, sz;
        cin >> t >> x >> sz;
        vector<int> ndp = dp;
        for (int x1 = 0; x1 <= 4; x1++) {
            for (int x2 = 0; x2 <= 4; x2++) {
                if (abs(x2 - x1) <= t - pt) {
                    ndp[x2] = max(ndp[x2], dp[x1] + (x2 == x ? sz : 0));
                }
            }
        }
        swap(dp, ndp);
        pt = t;
    }
    cout << *max_element(dp.begin(), dp.end());
    return 0;
}