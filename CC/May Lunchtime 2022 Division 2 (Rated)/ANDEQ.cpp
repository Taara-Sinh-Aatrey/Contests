#include<bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int AND = a[0];
    for (int i = 1; i < n; i++) {
      AND &= a[i];
    }
    int cnt = 0;
    for (int i = 0, j; i < n; i = j) {
      j = i + 1;
      int cur = a[i];
      while (j < n && cur != AND) {
        cur &= a[j++];
      }
      cnt += cur == AND;
    }
    cout << n - cnt << '\n';
  }
  return 0;
}