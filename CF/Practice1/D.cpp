/**
 *    author:  Taara Sinh Aatrey
 *    created: 17.08.2022 20:24:30
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    const int64_t inf = 1e18L + 5;
    int64_t ans = inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i + k <= n; i++) {
        int64_t mn = a[i], mx = a[i + k - 1];
        if (mn * 1LL * mx < 0) {
            ans = min(ans, abs(mn) + abs(mx) + min(abs(mn), abs(mx)));
        }
        else {
            ans = min(ans, max(abs(mn), abs(mx)));
        }
    }
    cout << ans;
    return 0;
}