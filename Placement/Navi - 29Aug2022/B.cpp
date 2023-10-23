/**
 *    author:  Taara Sinh Aatrey
 *    created: 29.08.2022 16:37:18
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif


signed main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int low, high, f;
    cin >> low >> high >> f;
    f *= 1000;
    const int inf = 1e18L + 5;
    vector<int> mn(f + 1, inf);
    vector<int> mx(f + 1, -inf);
    mn[0] = 0;
    mx[0] = 0;
    for (int x = low; x <= high; x++) {
        for (int i = 0; i + x <= f; i++) {
            mn[i + x] = min(mn[i + x], mn[i] + 1);
            mx[i + x] = max(mx[i + x], mx[i] + 1);
        }
    }
    cout << mn[f] << '\n';
    cout << mx[f] << '\n';
    return 0;
#undef int
}