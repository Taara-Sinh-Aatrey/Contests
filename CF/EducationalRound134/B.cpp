/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 20:09:21
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
        int n, m, sx, sy, D;
        cin >> n >> m >> sx >> sy >> D;
        int left = sy - D, right = sy + D, down = sx + D, up = sx - D;
        if ((left <= 1 && up <= 1) || (right >= m && down >= n) || (left <= 1 && right >= m) || (up <= 1 && down >= n)) {
            cout << -1 << '\n';
        }
        else {
            cout << (n + m - 2) << '\n';
        }
    }
    return 0;
}