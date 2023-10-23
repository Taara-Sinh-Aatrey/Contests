/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.10.2022 12:14:27
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
    int n;
    cin >> n;
    vector<int> a[2];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x % 2].emplace_back(x);
    }
    int ans = -1;
    for (int p = 0; p < 2; p++) {
        sort(a[p].begin(), a[p].end());
        if (a[p].size() >= 2) {
            ans = max(ans, a[p].back() + a[p][a[p].size() - 2]);
        }
    }
    cout << ans;
    return 0;
}