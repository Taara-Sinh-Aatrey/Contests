/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 08:29:29
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
    int testcases;
    cin >> testcases;
    for (int caseno = 1; caseno <= testcases; caseno++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] *= 2;
        }
        const int inf = 1e18L + 5;
        int mx = inf, mn = 0;
        for (int i = 0; i + 1 < n; i++) {
            int x = a[i], y = a[i + 1];
            if (x == y) {
                continue;
            }
            int diff = min(x, y) + abs(y - x) / 2;
            if (x < y) {
                mx = min(mx, diff);
            }
            else {
                mn = max(mn, diff);
            }
        }
        if (mn & 1) mn++;
        if (mx & 1) mx--;
        cout << (mn <= mx ? mn / 2 : -1) << '\n';
    }
    return 0;
}