/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.08.2022 21:12:38
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

/*

1 2 5 6 7 2 5 2 1

1 2 5 6 7 2 3 2 5 3

[0...j-1]    j  k        i
             x  x        x

 
1 2 2 2 2 2 2 2 1
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        const int inf = 1e18L + 5;
        vector<int> mn(n + 1, inf);
        // (i, j) => i and j doesn't change
        // [0.....i-1] i
        // [0....j] [j+1..........i]
        vector<int> dp(n, inf);
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] >= a[i - 1]) {
                dp[i] = (i == 0 ? 0 : dp[i - 1]);
            }
            dp[i] = min(dp[i], mn[a[i]] + 1);
            mn[a[i]] = min(mn[a[i]], dp[i]);
        }
        cout << (dp.back() < inf ? dp.back() : -1) << '\n';
    }
    return 0;
}