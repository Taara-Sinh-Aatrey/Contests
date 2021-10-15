#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    pair<int, int> ans;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    for(auto& [x1, f1] : cnt) {
      int x2 = x1 ^ k;
      int f2 = cnt[x2];
      ans = max(ans, pair(f1 + (x2 != x1 ? f2 : 0), -(x2 != x1 ? f2 : 0)));
    }
    cout << ans.first << " " << -ans.second << '\n';
  }
  return 0;
}