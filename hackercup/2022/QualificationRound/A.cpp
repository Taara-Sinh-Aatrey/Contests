/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.08.2022 22:31:19
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
        cout << "Case #" << tt << ": ";
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        bool ok = true;
        int sum = 0;
        vector<int> fr(3);
        for (auto &[ele, f] : mp) {
            if (f > 2) {
                ok = false;
            }
            else {
                fr[f]++;
            }
            sum += f;
        }
        ok &= sum <= 2 * k && fr[2] <= k;
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}