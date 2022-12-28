/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.12.2022 16:56:53
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
        const int inf = 1e18L + 5;
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        sort(a.begin(), a.end());
        a.emplace_back(inf);
        int ptr = 0;
        int cycle_gain = 0;
        int ans = 0;
        bool round1 = true;
        while (x < y) {
            int to_gain = max<int>(0, min(a[ptr], y) - (x + ptr));
            if (!round1 && cycle_gain <= 0) {
                ans = -1;
                break;
            }
            int rounds = round1 ? 0 : to_gain / cycle_gain;
            x += rounds * cycle_gain;
            ans += rounds * n;
            int req = y - x;
            if (req < ptr) {
                x += req;
                ans += req;
                break;
            }
            x += ptr;
            cycle_gain = ptr;
            ans += ptr;
            for (int i = ptr; i < n && x < y; i++) {
                if (x >= a[i]) {
                    x++;
                    cycle_gain++;
                    ans++;
                    ptr = max(ptr, i + 1);
                }
                else {
                    int rem = n - i;
                    x -= rem;
                    cycle_gain -= rem;
                    ans += rem;
                    break;
                }
            }
            round1 = false;
        }
        cout << ans << '\n';
    }
    return 0;
}