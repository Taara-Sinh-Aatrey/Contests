/**
 *    author:  Taara Sinh Aatrey
 *    created: 08.09.2022 14:07:19
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        string h = "hard";
        const int inf = 1e18L + 5;
        vector<int> dp(4, 0);
        for (int i = 0; i < n; i++) {
            size_t j = h.find(s[i]);
            if (j == string::npos)
                continue;
            vector<int> ndp(4, inf);
            for (int x = 0; x < 4; x++) {
                for (int y = x; y < 4; y++) {
                    ndp[y] = min(ndp[y], dp[x] + (y == j) * a[i]);
                }
            }
            swap(dp, ndp);
        }
        cout << *min_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}