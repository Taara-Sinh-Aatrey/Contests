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
      cin >> x;
    sort(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0LL);
    long double ans = 0;
    long double pref = 0;
    for (int i = 0; i < n - 1; i++) {
      pref += a[i];
      ans = max(ans, pref / (i + 1) + (sum - pref) / (n - i - 1));
    }
    cout << fixed << setprecision(20) << ans << '\n';
  }
  return 0;
}