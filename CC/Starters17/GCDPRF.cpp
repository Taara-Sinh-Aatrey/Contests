#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &x : b)
      cin >> x;
    vector<int> a(n);
    bool ok = true;
    for (int i = 1; i < n; i++) {
      // b[i] = __gcd(b[i - 1], a[i])
      if (b[i - 1] % b[i]) {
        ok = false;
        cout << -1;
        break;
      }
    }
    if (ok) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          cout << " ";
        }
        cout << b[i];
      }      
    }
    cout << '\n';
  }
}