#include "bits/stdc++.h"

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> suff(n);
    const int inf = 1e9 + 5;
    vector<int> extra(n);
    int ops = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (ops % 2 == 1) {
        extra[i] = s[i] == '0' ? 1 : -1;
      }
      if ((s[i] == '1') != (ops % 2 == 0)) {
        ops++;
      }
      suff[i] = ops;
    }
    int ans = inf;
    for (int i = 0; i + k <= n; i++) {
      int cur = suff[i] - (i + k == n ? 0 : suff[i + k]) + extra[i + k - 1];
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
  return 0;
}