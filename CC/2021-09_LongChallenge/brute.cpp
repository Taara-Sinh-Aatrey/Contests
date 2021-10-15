#include <bits/stdc++.h>

using namespace std;
#define int int64_t
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    int num, l, r;
    cin >> num >> l >> r;
    int B = -1, best = 2e9;
    int R = r;
    r = min(num, r);
    if(l <= num) {
      l = min(r, num / (num / l));
    }
    int q = num / l;
    int cnt = 0;
    for(int b = l; b <= r; ) {
      // cout << "b = " << b << '\n';
      int sum = 0, x = num;
      while(x > 0) {
        sum += x % b;
        x /= b;
      }
      cnt++;
      if(sum < best) {
        best = sum;
        B = b;
      }
      q--;
      if(q <= 0) break;
      int nxt = num / q;
      if(nxt > r) {
        nxt = r;
        q = num / nxt;
      }
      if(nxt == b) {
        nxt = b + 1;
        q = num / nxt;
      }
      b = nxt;
    }
    if(R > num && num < best) {
      B = max(num + 1, l);
      best = num;
    }
    // cout << B << '\n';
    cout << best << '\n';
    // cout << cnt << '\n';
  }
  return 0;
}