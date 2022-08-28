/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.08.2022 23:56:01
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n)), dp2(n, vector<int>(n, 0));
    vector<int> pref = a;
    for (int i = 1; i < n; i++) {
        pref[i] ^= pref[i - 1];
    }
    int ops = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            dp[i][j] = max(dp[i][j], (i + 1 <= j ? dp2[i + 1][j] : 0) + ((pref[j] ^ (i - 1 >= 0 ? pref[i - 1] : 0)) & (j - i + 1)));
            for (int k = i; k <= j; k++) {
                dp2[i][j] = max(dp2[i][j], dp[i][k] + (k + 1 <= j ? dp2[k + 1][j] : 0));
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}