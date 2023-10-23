/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.09.2022 20:34:35
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
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        const int inf = 1e18L + 5;
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        auto lcp = [&] (int j, int i) {
            int cl = 0;
            while (i + cl < j && j + cl < n && s[i + cl] == s[j + cl]) {
                cl++;
            }
            return cl;
        };
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n - i + 1, 0);
            for (int j = 0; j < i; j++) {
                int cl = lcp(i, j);
                bool greater = i + cl < n && s[j + cl] < s[i + cl];
                for (int l = 1; l <= n - j; l++) {
                    if (j + l > i) break;
                    if (l <= cl) {
                        if (i + l + 1 <= n)
                            dp[i][l + 1] = max(dp[i][l + 1], dp[j][l]);
                    }
                    else {
                        if (greater) {
                            if (i + cl + 1 <= n)
                                dp[i][cl + 1] = max(dp[i][cl + 1], dp[j][l]);
                        }
                        else {
                            break;
                        }
                    }
                }
            }
            for (int l = 1; l <= n - i; l++) {
                dp[i][l] = max(dp[i][l], dp[i][l - 1]);
            }
            for (int l = 1; l <= n - i; l++) {
                dp[i][l] += a[l - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                ans = max(ans, dp[i][j]);
            }
        } 
        cout << ans << '\n';
    }
    return 0;
}