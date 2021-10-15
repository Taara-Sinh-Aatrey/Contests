#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> cnt = {(n + 1) / 2, n / 2};
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += cnt[x % 2]-- > 0;
    }
    cout << ans << '\n';
  }
  return 0;
}