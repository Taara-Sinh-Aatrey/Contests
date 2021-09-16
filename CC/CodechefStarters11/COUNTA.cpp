#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
      cin >> a[i];
    }
    map<pair<int, int>, int> dp;
    const int MAX = 1e5;
    dp[{0, MAX}] =  1;
    auto intersect = [&](int f, int s, int ff, int ss) {
      int fff = max(f, ff);
      int sss = min(s, ss);
      return pair(fff, sss);
    };
    for(int i = 0; i < n - 1; i++) {
      map<pair<int, int>, int> ndp;
      for(auto& [P, ways] : dp) {
        auto& [l, r] = P;
        // a[i] ,           [a[i]+1, MAX]
        {
          auto [nl, nr] = intersect(l, r, a[i], a[i]);
          if(nl <= nr && a[i] < MAX) {
            ndp[{a[i] + 1, MAX}] += ways * (nr - nl + 1) % mod;
            ndp[{a[i] + 1, MAX}] %= mod;
          }
        }
        // [a[i], MAX]      a[i]
        {
          auto [nl, nr] = intersect(l, r, a[i], MAX);
          if(nl <= nr) {
            ndp[{a[i], a[i]}] += ways * (nr - nl + 1) % mod;
            ndp[{a[i], a[i]}] %= mod;
          }
        }
      }
      dp = ndp;
    }
    int ans = 0;
    for(auto& [P, ways] : dp) {
      auto& [l, r] = P;
      ans += ways * (r - l + 1) % mod;
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}