#include <bits/stdc++.h>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while(t--) {
    long long num, r;
    cin >> num >> r;
    long long l = 2;
    long long B = -1, best = 2e9;
    long long R = r;
    r = min(num, r);
    if(l <= num) {
      l = min(r, num / (num / l));
    }
    long long q = num / l;
    for(long long b = l; b <= r; ) {
      long long sum = 0, x = num;
      while(x > 0) {
        sum += x % b;
        x /= b;
      }
      if(sum < best) {
        best = sum;
        B = b;
      }
      q--;
      if(q <= 0) break;
      long long nxt = num / q;
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
    cout << B << '\n';
  }
  return 0;
}