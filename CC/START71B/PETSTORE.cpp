/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.12.2022 09:10:59
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      freq[x]++;
    }
    bool ok = true;
    for (auto &[x, fr] : freq) {
      ok &= fr % 2 == 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}