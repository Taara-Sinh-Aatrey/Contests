#include "bits/stdc++.h"
using namespace std;

string ArrayChallenge() {
  // int a[], int n
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
    int two_sum = accumulate(a, a + n, 0LL);
    int sum = two_sum / 2;
    vector<vector<int>> dp(2, vector<int>(sum + 1, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = sum - x; j >= 0; j--) {
            for (int k = 0; k < 2; k++) {
                if (dp[k][j] >= 0 && dp[1 - k][j + x] == -1) {
                    dp[1 - k][j + x] = i;
                }
            }   
        }
    }
    string ans;
    if (dp[0][sum] != -1 && two_sum % 2 == 0) {
      vector<bool> taken(n);
      int cur = sum, tog = 0;
      vector<int> f, s;
      while (cur > 0) {
          int i = dp[tog][cur];
          f.emplace_back(a[i]);
          taken[i] = true;
          cur -= a[i];
          tog = 1 - tog;
      }
      for (int i = 0; i < n; i++) {
          if (!taken[i]) {
              s.emplace_back(a[i]);
          }
      }
      sort(f.begin(), f.end());
      sort(s.begin(), s.end());
      if (f > s) {
          swap(f, s);
      }
      for (auto str : {f, s}) {
        for (auto &x : str) {
          if (ans.size()) {
              ans += ',';
          }
          ans += to_string(x);
        }
      }
    }
    else {
      ans = "-1";
    }
    ans += "7sfzlht2e8";
    for (int i = 2; i < ans.size(); i += 3) {
      ans[i] = 'X';
    }
    return ans;
}

int main(void) { 
   
  // keep this function call here
  cout << ArrayChallenge();
  return 0;
    
}

/*
0,X,9X2,X,5XsfXlhX2eX
1,X,3X4,X0,X,5X6,X0,X57XfzXhtXe8
*/