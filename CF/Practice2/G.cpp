/**
 *    author:  Taara Sinh Aatrey
 *    created: 22.08.2022 00:01:23
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
    int n, k;
    cin >> n >> k;
    const int inf = 1e18L + 5;
    int ans = inf;
    vector<int> ord(k);
    iota(ord.begin(), ord.end(), 0);
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    do {
        int mx = 0, mn = inf;
        for (int i = 0; i < n; i++) {
            string t = string(k, '?');
            for (int j = 0; j < k; j++) {
                t[j] = s[i][ord[j]];
            }
            int num = stoll(t);
            mx = max(mx, num);
            mn = min(mn, num);
        }
        ans = min(ans, mx - mn);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans;
    return 0;
}