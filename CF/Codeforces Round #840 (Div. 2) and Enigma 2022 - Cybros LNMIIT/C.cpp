/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.12.2022 16:58:36
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
        for (auto &x : a) {
            cin >> x;
        }
        int mx = *max_element(a.begin(), a.end());
        if (n == 1) {
            cout << a[0] << '\n';
        }
        else if (n == 2) {
            cout << max(a[0] + a[1], 2 * abs(a[0] - a[1])) << '\n';
        }
        else if (n == 3) {
            cout << max(a[0] + a[1] + a[2], 3 * max({a[0], a[2], abs(a[0] - a[1]), abs(a[1] - a[2]), abs(a[0] - a[2])})) << '\n';
        }
        else if (n >= 4) {
            cout << n * mx << '\n';
        }
    }
    return 0;
}