/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.12.2022 14:15:47
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for (auto &row : a) {
            for (auto &x : row) {
                cin >> x;
            }
        }
        auto check = [&] (int l) -> bool {
            vector<vector<int>> dp(n + 1, vector<int>(m + 1));
            bool any = false;
            for (int i = n - 1; i >= 0; i--) {
                for (int j = m - 1; j >= 0; j--) {
                    if (a[i][j] >= l) {
                        dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                        any |= dp[i][j] >= l;
                    }
                }
            }
            return any;
        };
        int low = 1, high = min(n, m);
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << high << '\n';
    }
    return 0;
}