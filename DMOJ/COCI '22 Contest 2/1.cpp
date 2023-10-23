/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.12.2022 18:52:54
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
    vector<int> a(n + 2);
    const int inf = 1e18L + 5;
    pair<int, int> ans{inf, inf};
    for (int i = 2; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "Patrik") {
            cin >> a[i];
        }
        else {
            int prev;
            cin >> prev >> a[i];
            a[i] += a[prev];
        }
        ans = min(ans, pair(a[i] - a[i - 1], i));
    }
    cout << ans.first << " " << ans.second - 1 << " " << ans.second << '\n';
    return 0;
}