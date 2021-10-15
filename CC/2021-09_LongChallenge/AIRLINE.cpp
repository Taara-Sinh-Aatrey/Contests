#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    vector<int> a(3), b(2);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
      sum += a[i];
    }
    for (int i = 0; i < 2; i++) {
      cin >> b[i];
    }
    vector<vector<int>> comb = {{0, 1}, {1, 2}, {2, 0}};
    bool poss = false;
    for(vector<int> v : comb) {
      int x = 0, y = sum;
      for (int i : v) {
        x += a[i];
        y -= a[i];
      }
      if(x <= b[0] and y <= b[1]) {
        poss = true;
        break;
      }
    }
    cout << (poss ? "YES" : "NO") << '\n';
  }
  return 0;
}