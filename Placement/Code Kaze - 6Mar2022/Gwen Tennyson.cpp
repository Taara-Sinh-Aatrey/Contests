int numWays(int n, int m) {
    const int mod = 1e9 + 7;
    int dp[n][m][2][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 2; dir++) {
                for (int steps = 0; steps <= 2; steps++) {
                    dp[i][j][dir][steps] = 0;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;
    // i j right/down steps = ways
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int steps = 0; steps <= 2; steps++) {
                if (steps < 2 && i + 1 < n) {
                    dp[i + 1][j][0][steps + 1] += dp[i][j][0][steps];
                    dp[i + 1][j][0][steps + 1] %= mod;
                }
                if (i + 1 < n) {
                    dp[i + 1][j][0][1] += dp[i][j][1][steps];
                    dp[i + 1][j][0][1] %= mod;
                }
                
                if (steps < 2 && j + 1 < m) {
                    dp[i][j + 1][1][steps + 1] += dp[i][j][1][steps];
                    dp[i][j + 1][1][steps + 1] %= mod;
                }
                if (j + 1 < m) {
                    dp[i][j + 1][1][1] += dp[i][j][0][steps];
                    dp[i][j + 1][1][1] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int dir = 0; dir < 2; dir++) {
        for (int steps = 0; steps <= 2; steps++) {
            ans += dp[n - 1][m - 1][dir][steps];
            ans %= mod;
        }
    }
    return ans;
}