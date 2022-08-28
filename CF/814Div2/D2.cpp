/**
 *    author:  Taara Sinh Aatrey
 *    created: 16.08.2022 22:42:44
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> where;
        where[0] = -1;
        vector<int> dp(n);
        int pref = 0;
        int mn = 0;
        for (int i = 0; i < n; i++) {
            mn++;
            pref ^= a[i];
            dp[i] = mn;
            if (where.count(pref)) {
                int j = where[pref];
                dp[i] = min(dp[i], (i - j - 1) + (j >= 0 ? dp[j] : 0));
            }
            mn = min(mn, dp[i]);
            where[pref] = i;
        }
        cout << dp.back() << '\n';
    }
    return 0;
}