#include <bits/stdc++.h>

using namespace std;
#define int int64_t
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Q;
  cin >> Q;
  int x, a, b, c, d;
  cin >> x >> a >> b >> c >> d;
  int p, q, r, s, t, m;
  cin >> p >> q >> r >> s >> t >> m;
  while(Q--) {
    int lo = min(a, c), hi = x;
    int ans = 0;
    while(lo <= hi) {
      __int128 mid = (lo + hi) / 2;
      __int128 ca = (mid - a) / b;
      __int128 A = a + b * ca;
      ca++;
      if(a > mid) {
        ca = 0;
        A = 0;
      }
      __int128 cc = (mid - c) / d;
      __int128 C = c + d * cc;
      cc++;
      if(c > mid) {
        cc = 0;
        C = 0;
      }
      __int128 sum = (A + a) * ca / 2 + (C + c) * cc / 2;
      if(sum > x) {
        sum -= max(A, C);
        ca--;
      }
      if(sum <= x) {
        ans = ca + cc;
        lo = mid + 1;
      }
      else {
        hi = mid - 1;
      }
    }
    cout << ans << '\n';
    int add = ans * t % m;
    a = (a + add) % m + p;
    b = (b + add) % m + q;
    c = (c + add) % m + r;
    d = (d + add) % m + s;
  }
  return 0;
}