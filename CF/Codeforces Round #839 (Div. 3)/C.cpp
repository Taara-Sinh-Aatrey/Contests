/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 08:08:24
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
        int k, n;
        cin >> k >> n;
        int low = 1, high = k - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int ones = k - 1 - mid;
            int x = 1 + ones, inc = 1;
            for (int i = ones; i < k - 1; i++) {
                x += inc++;
            }
            if (x <= n) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        int ones = k - 1 - high;
        for (int i = 1; i <= 1 + ones; i++) {
            cout << i << " ";
        }
        int x = 1 + ones, inc = 1;
        for (int i = ones; i < k - 1; i++) {
            x += inc++;
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}