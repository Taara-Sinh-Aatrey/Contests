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

signed main() {
    int n, m;
    cin >> n >> m;
    int sum = -m;
    int pts = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pts += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }
    vector<int> ones, twos;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ones.emplace_back(b[i]);
        }
        else {
            twos.emplace_back(b[i]);
        }
    }
    sort(ones.begin(), ones.end());
    ones.insert(ones.begin(), 0);
    sort(twos.begin(), twos.end());
    for (int i = 1; i < ones.size(); i++) {
        ones[i] += ones[i - 1];
    }
    for (int i = 1; i < twos.size(); i++) {
        twos[i] += twos[i - 1];
    }
    int take = 0;
    for (int i = 0; i < ones.size(); i++) {
        if (ones[i] > sum) break;
        take = max(take, i + 2 * (upper_bound(twos.begin(), twos.end(), sum - ones[i]) - twos.begin()));
    }
    cout << (pts - take) << '\n';
    return 0;
}