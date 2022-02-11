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

void solve() {
       int n;
       cin >> n;
       vector<int> a(n), b(n);
       for (int i = 0; i < n; i++) {
          cin >> a[i] >> b[i];
       }
       vector<int> dp(n);
       for (int i = 0; i < n; i++) {
          dp[i] = max((i - 1 >= 0 ? dp[i - 1] : 0) + a[i], (i - 2 >= 0 ? dp[i - 2] : 0) + b[i]);
       }
       cout << dp[n - 1];
}

int main() {

       solve();

       return 0;
}