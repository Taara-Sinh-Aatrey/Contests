#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (auto &x : b) {
            cin >> x;
        }
        vector<int> mna = a, mxa = a, mnb = b, mxb = b;
        mna.insert(mna.begin(), inf);
        mxa.insert(mxa.begin(), -inf);
        mnb.insert(mnb.begin(), inf);
        mxb.insert(mxb.begin(), -inf);
        for (int i = 1; i <= n; i++) {
            mna[i] = min(mna[i], mna[i - 1]);
            mxa[i] = max(mxa[i], mxa[i - 1]);
        }
        for (int i = 1; i <= m; i++) {
            mnb[i] = min(mnb[i], mnb[i - 1]);
            mxb[i] = max(mxb[i], mxb[i - 1]);
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + max(mxa[i], mxb[j]) - min(mna[i], mnb[j]));
                }
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + max(mxa[i], mxb[j]) - min(mna[i], mnb[j]));
                }
            }
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}