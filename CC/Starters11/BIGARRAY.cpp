#include<bits/stdc++.h>

using namespace std;
#define int int64_t
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, s;
    cin >> n >> s;
    if(n * (n - 1) / 2 <= s && s < n * (n + 1) / 2) {
      cout << n*(n+1)/2-s;
    }
    else {
      cout << -1;
    }
    cout << '\n';
  }
  return 0;
}