/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.09.2022 14:35:55
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
        string s;
        cin >> s;
        int n = s.size();
        int w, q;
        cin >> w >> q;
        vector<int> pref(n + 1);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (s[i - 1] - '0');
        }
        vector<vector<int>> pos(9);
        int L = 0, R = 0, sum = 0;
        while (R < w - 1) {
            sum += s[R++] - '0';
        }
        while (R < n) {
            sum += s[R++] - '0';
            pos[sum % 9].emplace_back(L);
            sum -= s[L++] - '0';
        }
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k, --l, --r;
            int s = pref[r + 1] - pref[l];
            pair<int, int> ans{n, n};
            for (int s1 = 0; s1 < 9; s1++) {
                if (pos[s1].empty()) continue;
                // s1 * s + s2 = k
                // s2 = k - s1 * s
                int s2 = (k - s1 * s % 9 + 9) % 9;
                if (pos[s2].size() < 1 + (s1 == s2)) continue;
                pair<int, int> cur = {*pos[s1].begin(), s1 == s2 ? *next(pos[s2].begin()) : *pos[s2].begin()};
                ans = min(ans, cur);
            }
            if (ans == pair<int, int>(n, n)) {
                ans = pair<int, int>(-2, -2);
            }
            cout << ans.first + 1 << " " << ans.second + 1 << '\n';
        }
    }
    return 0;
}