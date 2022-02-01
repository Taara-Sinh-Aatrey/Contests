#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

void solve () {
    int hc, dc, hm, dm, k, di, hi;
    cin >> hc >> dc >> hm >> dm >> k >> di >> hi;
    bool ok = false;
    for (int i = 0; i <= k; i++) {
        int nhc = hc + i * hi;
        int ndc = dc + (k - i) * di;
        int x = (nhc + dm - 1) / dm;
        int y = (hm + ndc - 1) / ndc;
        if (x >= y) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}