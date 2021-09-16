#include "bits/stdc++.h"
using namespace std;

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

signed main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    auto sum = [&](int low, int high) {
        assert(low <= high);
        return (low + high) * (high - low + 1) / 2;
    };
    cout << (sum(a, b) + sum(c, b) - b);
    return 0;
}