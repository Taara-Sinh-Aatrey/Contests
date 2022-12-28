/**
 *    author:  Taara Sinh Aatrey
 *    created: 28.12.2022 14:57:45
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
        int n, m;
        cin >> n >> m;
        vector<int> cnt(n + 1);
        vector<int> a;
        int ans = 0;
        int constructed = 0;
        for (int i = n; i >= 2; i--) {
            int multiples = n / i;
            cnt[i] = multiples * (multiples - 1) / 2;
            for (int j = 2 * i; j <= n; j += i) {
                cnt[i] -= cnt[j];
            }
            int req = m - constructed;
            int have = cnt[i];
            int take = min(req, have) / (i - 1) * (i - 1);
            constructed += take;
            ans += take / (i - 1) * i;
        }
        if (constructed < m) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}