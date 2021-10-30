#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
   int n;
   cin >> n;
   cout << 1 << " ";
   for (int i = 0; i < n; i++) {
    cout << (1LL << i) << " \n"[i == n - 1];
   }
  }
  return 0;
}