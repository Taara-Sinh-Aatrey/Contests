#include<bits/stdc++.h>

using namespace std;
#define int int64_t
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(i == j) {
          cout << -1;
        }
        else {
          cout <<  (n & 1 ? 1 : -1);
        }
        cout << " \n"[j == n - 1];
      }
    }
  }
  return 0;
}