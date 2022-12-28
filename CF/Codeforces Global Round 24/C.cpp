/**
 *    author:  Taara Sinh Aatrey
 *    created: 01.12.2022 00:53:38
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
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        vector<int> a;
        for (auto &[x, fr] : mp) {
            a.emplace_back(fr);
        }
        int ans = n / 2;
        for (int rep = 0; rep < 2; rep++) {
            int cur = 0, i = 0;
            while (i < a.size() && cur + a[i] <= n / 2) {
                cur += a[i++];
            }
            ans = max(ans, cur * (n - cur));
            reverse(a.begin(), a.end());
        }
        cout << ans << '\n';
    }
    return 0;
}