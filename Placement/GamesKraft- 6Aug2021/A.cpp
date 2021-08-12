#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

int maxPathSum(vector<vector<int>> board, int p, int q) {
    
    int n = board.size(), m = board[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][p] = board[0][p];
    
    int ans = 0;
    
    for(int i = 0; i < n; i++)  {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
            if(i + 1 < n) {
            
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + board[i + 1][j]);
                
                if(j + 1 < m)
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + board[i + 1][j + 1]);
                
                if(j - 1 >= 0)
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + board[i + 1][j - 1]);
            }
            dp[i][j] = 0;
        }
    }
    
    dp[n - 1][q] = board[n - 1][q];
    
    for(int i = n - 1; i >= 0; i--)  {
        for(int j = 0; j < m; j++) {
            ans = max(ans, dp[i][j]);
            if(i - 1 >= 0) {
            
                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] + board[i - 1][j]);
                
                if(j + 1 < m)
                    dp[i - 1][j + 1] = max(dp[i - 1][j + 1], dp[i][j] + board[i - 1][j + 1]);
                
                if(j - 1 >= 0)
                    dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j] + board[i - 1][j - 1]);
            }
            dp[i][j] = 0;
        }
    }
    
    return ans;
    
}

signed main()
{
    cout << maxPathSum({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1, 0) << endl;
    cout << maxPathSum({{9, 4, 7}, {2, 1, 3}, {1, 4, 2}}, 2, 1) << endl;
    
    return 0;
}