#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, inf));
    for (int i = n - 1; i >= 0; i--) {
        vector<vector<bool>> divides(n, vector<bool>(n, false));
        for (int j = i; j < n; j++) {
            int l = (j - i + 1);
            int k = i;
            while (k < n && s[k] == s[i + (k - i) % l]) {
                if ((k - i + 1) % l == 0) {
                    divides[j][k] = true;
                }
                k++;
            }
        }
        for (int k = i; k < n; k++) {
            dp[i][k] = k - i + 1;
            for (int j = i; j <= k; j++) {
                if (divides[j][k]) {
                    int c = (k - i + 1) / (j - i + 1);
                    int cl = to_string(c).length();
                    dp[i][k] = min(dp[i][k], dp[i][j] + cl + 2);
                }
                if (j < k)
                    dp[i][k] = min(dp[i][k], dp[i][j] + dp[j + 1][k]);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}