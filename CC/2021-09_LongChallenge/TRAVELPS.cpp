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
    vector<int> cost(2);
    for (int i = 0; i < 2; i++) {
      cin >> cost[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      char ch;
      cin >> ch;
      ans += cost[ch - '0'];
    }
    cout << ans << '\n';
  }
  return 0;
}