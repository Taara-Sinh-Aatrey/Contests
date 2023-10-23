#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = dp[i][j - 1];
      dp[i][j] = max(dp[i][j], dp[i + 1][j]);
      dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + (s[i] == s[j]) * 1);
    }
  }
  cout << dp[0][n - 1] << '\n';  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}