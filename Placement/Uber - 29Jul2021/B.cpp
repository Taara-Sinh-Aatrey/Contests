#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int solve(string s) {
    int n = s.size();
    s = "?" + s;
    int ans = n;
    
    for(int p = 1; p <= n; p++) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
        for(int i = 0; i <= n; i++) {
            dp[0][i] = max<int>(0, i - p + 1);
        }
        for(int i = 1; i < p; i++) {
            for(int j = p; j <= n; j++) {
                dp[i][j] = min({dp[i][j], dp[i - 1][j - 1] + (s[i] != s[j]), 1 + dp[i - 1][j], 1 + dp[i][j - 1]});  
            }
        }
        
        ans = min(ans, dp[p - 1][n]);
    }
    
    return ans;
}

signed main()
{
    cout << solve("xyx") << endl;
    cout << solve("a") << endl;
    cout << solve("abbbbcxa") << endl;
    cout << solve("acwbawxb") << endl;

    return 0;
}