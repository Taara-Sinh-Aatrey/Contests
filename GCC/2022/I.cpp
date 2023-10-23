/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.10.2022 08:30:28
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    int n;
    scanf("%d", &n);
    int pref[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        static char s[51];
        scanf("%s", s);
        for (int j = 1; j <= n; j++) {
            pref[i][j] = (s[j - 1] == '$') + pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
        }
    }
    int dp[n + 1][n + 1][n + 1][n + 1];
    const int inf = 1e9 + 5;
    for (int a = n; a >= 1; a--) {
        for (int b = n; b >= 1; b--) {
            for (int c = a; c <= n; c++) {
                for (int d = b; d <= n; d++) {
                    int sum = pref[c][d] - pref[a - 1][d] - pref[c][b - 1] + pref[a - 1][b - 1];
                    dp[a][b][c][d] = sum == 0 ? 0 : (c - a == d - b ? c - a + 1 : inf);
                    /*
                    a,b           | a,y+1
                                  |
                                  |
                                  |
                    ____________x,y              x,d
                    x+1,b
                                
                                  
                                  
                                c,y              c,d
                    */
                    for (int x = a; x < c; x++) {
                        dp[a][b][c][d] = min(dp[a][b][c][d], dp[a][b][x][d] + dp[x + 1][b][c][d]);
                    }
                    for (int x = b; x < d; x++) {
                        dp[a][b][c][d] = min(dp[a][b][c][d], dp[a][b][c][x] + dp[a][x + 1][c][d]);
                    }
                }
            }
        }
    }
    cout << dp[1][1][n][n] << '\n';
    return 0;
}