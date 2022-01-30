#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
      cin >> x, --x;
    vector<int> mn = a, mx = a;
    vector<int> where(n, -1);
    for (int i = 0; i < n; i++) {
      if (i > 0)
        mn[i] = min(mn[i - 1], a[i]);
      if (where[mn[i]] == -1)
        where[mn[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i + 1 < n)
        mx[i] = max(mx[i + 1], a[i]);
    }
    bool ok = true;
    int curMn = 0;
    while (true) {
      int idx = where[curMn];
      assert(idx != -1);
      int curMx = mx[idx];
      if (idx == 0)
        break;
      // idx .......n - 1
      
      // 0 ..... idx-1
      int nxtMn = mn[idx - 1];
      if (nxtMn > curMx) {
        ok = false;
        break;
      }
      curMn = nxtMn;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}