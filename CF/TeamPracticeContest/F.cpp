/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.08.2022 00:55:46
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
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    const int inf = 1e18L + 5;
    int ans = inf;
    for (int start = 0; start < n; start++) {
        int cur = 0;
        int low = start - 1, high = start + 1;
        for (int taken = 1; taken < n;) {
            if (low < 0 || (high < n && (a[high] - a[high - 1]) * (low - (lower_bound(a.begin(), a.end(), a[low]) - a.begin()) + 1) < (a[low + 1] - a[low]) * (upper_bound(a.begin(), a.end(), a[high]) - a.begin() - high))) {
                int cnt = upper_bound(a.begin(), a.end(), a[high]) - a.begin() - high;
                cur += (a[high] - a[low + 1]) * cnt;
                high += cnt;
                taken += cnt;
            }
            else {
                int cnt = low - (lower_bound(a.begin(), a.end(), a[low]) - a.begin()) + 1;
                cur += (a[high - 1] - a[low]) * cnt;
                low -= cnt;
                taken += cnt;
            }
        }
        ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}