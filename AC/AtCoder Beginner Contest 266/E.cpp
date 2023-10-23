// 1 => 1/6 => 3.5/6
// 2 => 1/6 => 3.5/6
// 3 => 1/6 => 3.5/6

// // 4 => 1/6
// // 4 => 3.5

// // 5 => 1/6
// // 3.5

// 6 => 1/6 => 3

// 3.5 + 3.5*3/6
// (4+5+6)/6 + 1.75 = 2.5 + 1.75 = 4.25

/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 18:37:55
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
#define ld long double

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ld> dp(7);
    dp[6] = 0;
    ld prob = 1;
    for (int i = 0; i < n; i++) {
        prob *= 1.0 / 6;
        vector<ld> ndp(7);
        for (int x = 0; x <= 6; x++) { // x elements to go again
            int y = 6 - x; // y elements already stopped sometime before
            for (int stop = 0; stop <= x; stop++) {
                ld ev = 0;
                for (int st = 0; st < stop; st++) {
                    ev += (6 - y - st) * prob;
                }
                ndp[x - stop] = max(ndp[x - stop], dp[x] + ev);
            }
        }
        swap(dp, ndp);
        dbg(dp);
    }
    ld ans = 0;
    for (int x = 0; x <= 6; x++) {
        int y = 6 - x;
        ld ev = 0;
        for (int stop = 0; stop < x; stop++) {
            ev += (6 - y - stop) * prob;
        }
        dbg(x, ev);
        ans = max(ans, dp[x] + ev);
    }
    cout << ans;
    return 0;
}