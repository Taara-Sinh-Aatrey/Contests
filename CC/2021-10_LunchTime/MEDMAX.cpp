#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
   long long n, k;
   cin >> n >> k;
   const long long N = n * n;
   vector<long long> a(N);
   for (long long i = 0; i < N; i++) {
     cin >> a[i];
   }
   sort(a.begin(), a.end());
   long long lo = n / 2, hi = n / 2 * n;
   long long ans = -1;
   while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    long long cost = a[mid], prev = mid;
    for (int i = 1; i < n; i++) {
      long long idx = max(prev + 1, n / 2 * (i + 1) + i);
      cost += a[idx];
      prev = idx;
    }
    if (cost <= k) {
      ans = max(ans, a[mid]);
      lo = mid + 1;
    }
    else {
      hi = mid - 1;
    }
   }
  cout << ans << '\n';
  }
  return 0;
}