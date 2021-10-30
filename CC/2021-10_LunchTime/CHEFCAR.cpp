#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
   long long n, v;
   cin >> n >> v;
   long long mn = min(v, n - 1);
   if (n - 1 > v) {
    // 2    n-v
    mn += (2 + n - v) * (n - v - 1) / 2;
   }
   long long mx = (n - 1) * 1LL * n / 2;
   cout << mx << " " << mn << '\n';
  }
  return 0;
}