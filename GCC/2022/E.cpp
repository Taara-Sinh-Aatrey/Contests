/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.10.2022 07:00:56
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

signed main() {
    int cutoff;
    scanf("%d", &cutoff);
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    int ans = 0, sum = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        while (j <= i && sum >= cutoff) {
            sum -= a[j++];
        }
        ans += i - j + 1;
    }
    cout << ans << '\n';
    return 0;
}