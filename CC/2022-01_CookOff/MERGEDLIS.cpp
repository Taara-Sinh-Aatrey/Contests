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
    auto Lis = [&] (vector<int> &a) {
      vector<int> lis;
      for (auto &x : a) {
        if (lis.empty() || x >= lis.back()) {
          lis.emplace_back(x);
        }
        else {
          auto it = upper_bound(lis.begin(), lis.end(), x);
          *it = x;
        }
      }
      return lis.size();
    };
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
      cin >> x;
    for (auto &x : b)
      cin >> x;
    cout << Lis(a) + Lis(b) << '\n';
  }
  return 0;
}