/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.08.2022 20:20:15
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

/*
1 5
-1 -2

0 4
-1 -2

-1 2
-1 -2

-2 0
-1 -2

1 5 3


<= 0 <=1 stop


*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            int ops = min(a[i], a[i + 1] / 2);
            if (ops > 0) {
                a[i] -= ops;
                a[i + 1] -= 2 * ops;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            // >1 <2
            int ops = a[i + 1] / 2;
            if (ops > 0) {
                a[i + 1] -= 2 * ops;
                a[i] -= ops;
            }
            // <1 0
            if (a[i + 1] == 1 && a[i] > 0) {
                a[i + 1] -= 2;
                a[i] -= 1;
            }
        }
        for (auto &x : a) {
            ans += abs(x);
        }
        cout << ans << '\n';
    }
    return 0;
}

// [6, -1, -1, -7, 0, -8, 0]

// 3 2 1
// 3 1 -1
// 2 -1 -1 = 4

// 3 2 1
// 2 0 1

// <1 <2 => <3
// <1 0 => <1
// <1 >2 not good
// >1 <2 => <1
// >1 0 not good
// >1 >2 too bad


