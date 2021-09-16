#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e18L  + 5;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    vector<int> d(n, inf);
    int sum = 0;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if(x > 0) {
        sum += x;
        d[i] = 0;
        q.emplace(i);
      }
    }
    if(q.empty()) {
      cout << 0 << '\n';
      continue;
    }
    while(!q.empty()) {
      int i = q.front();
      q.pop();
      for(int j : {i - 1, i + 1}) {
        if(j < 0) j += n;
        if(j >= n) j -= n;
        if(d[j] > d[i] + 1) {
          d[j] = d[i] + 1;
          q.emplace(j);
        }
      }
    }
    for(int i = 0; i < n; i++){
      int mn = inf, mx = -inf;
      for(int j : {i - 1, i + 1}) {
        if(j < 0) j += n;
        if(j >= n) j -= n;
        mn = min(mn, d[j]);        
        mx = max(mx, d[j]);
      }
      if(mn >= k) continue;
      mx = min(mx, k);
      sum += mx - mn;
      sum += (k - mx) * 2;
    }
    cout << sum << '\n';
  }
  return 0;
}