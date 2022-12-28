/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.09.2022 14:21:12
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
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a[i] = x - a[i];
        }
        sort(a.begin(), a.end());
        int L = 0, R = n - 1;
        int ans = 0;
        while (L < R) {
            if (a[L] + a[R] < 0)
                L++;
            else
                L++, R--, ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}