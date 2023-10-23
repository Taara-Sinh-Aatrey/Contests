/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.10.2022 08:03:57
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    int m, n;
    scanf("%d %d", &m, &n);
    m <<= 1;
    const int inf = 1e9 + 5;
    int dp[m + 1];
    fill(dp, dp + m + 1, -inf);
    dp[0] = 0;
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = min(m - 1, 2 * i); j >= 0; j--) {
            dp[j + 1] = max(dp[j + 1], dp[j] + ((j + 1) & 1 ? -x : x));
        }
    }
    cout << *max_element(dp, dp + m + 1);
    return 0;
}