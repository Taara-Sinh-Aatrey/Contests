/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2022 18:03:33
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int val = 0;
    int sum = 0;
    const int inf = 1e18L + 5;
    int ans = -inf;
    for (int i = 0; i < n; i++) {
        val += (i + 1) * a[i];
        sum += a[i];
        if (i >= m) {
            val -= (i - m + 1) * a[i - m];
            sum -= a[i - m];
        }
        if (i >= m - 1)
            ans = max(ans, val - sum * (i - m + 1));
    }
    cout << ans;
    return 0;
}