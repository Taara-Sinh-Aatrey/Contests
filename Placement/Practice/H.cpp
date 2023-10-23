/**
 *    author:  Taara Sinh Aatrey
 *    created: 12.10.2022 19:05:53
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


vector<int> solve(vector<int> n, vector<int> m, vector<int> totalCost) {
    vector<int> ret;
#define int int64_t
    const int mod = 1e9 + 7;
    for (int it = 0; it < n.size(); it++) {
        vector<vector<int>> dp(m[it] + 1, vector<int>(totalCost[it] + 2));
        for (int i = 1; i <= m[it]; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n[it]; i++) {
            vector<vector<int>> ndp(m[it] + 1, vector<int>(totalCost[it] + 2));
            for (int mx = 1; mx <= m[it]; mx++) {
                for (int tc = 0; tc <= totalCost[it]; tc++) {
                    for (int cur = 1; cur <= m[it]; cur++) {
                        ndp[max(mx, cur)][tc + (cur > mx ? 1 : 0)] += dp[mx][tc];
                        ndp[max(mx, cur)][tc + (cur > mx ? 1 : 0)] %= mod;
                    }                    
                }
            }
            swap(dp, ndp);
        }
        int ans = 0;
        for (int i = 1; i <= m[it]; i++) {
            ans += dp[i][totalCost[it]];
            ans %= mod;
        }
        ret.emplace_back(ans);
    }
    return ret;
#undef int
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> ans = solve({2, 3, 4}, {3, 3, 3}, {1, 2, 2});
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}