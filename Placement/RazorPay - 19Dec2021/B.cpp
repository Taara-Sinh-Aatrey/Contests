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

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    int ans = inf;
    for (int rep = 0; rep < n; rep++) {
        int cost = 0;
        for (int i = 0; i < n; i++) {
            b[i] = min(b[i], a[i]);
            cost += b[i];
        }
        ans = min(ans, rep * x + cost);
        a.insert(a.begin(), a.back());
        a.pop_back();
    }
    cout << ans << '\n';
    return 0;
}