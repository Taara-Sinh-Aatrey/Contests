/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 23:40:41
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
    pair<int, int> me;
    cin >> me.first >> me.second;
    long double ans = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> he;
        cin >> he.first >> he.second;
        int x = he.first - me.first;
        int y = he.second - me.second;
        long double cur = sqrtl(x * x + y * y);
        ans = max(ans, cur);
    }
    cout << fixed << setprecision(20) << ans << '\n';
    return 0;
}