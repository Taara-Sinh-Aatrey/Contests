/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 20:06:18
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
        map<char, int> mp;
        for (int i = 0; i < 2; i++) {
            string s;
            cin >> s;
            for (auto &ch : s) {
                mp[ch]++;
            }
        }
        int ans = 0, mx = 0;
        for (auto &[ch, f] : mp) {
            int cur = (f + 1) / 2;
            mx = max(mx, cur);
            ans += cur;
        }
        ans -= mx;
        cout << ans << '\n';
    }
    return 0;
}