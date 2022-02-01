#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

void solve() {
    int num;
    cin >> num;
    if (num % 7 != 0) {
        num -= num % 10;
        while (num % 7 != 0)
            num++;
    }
    cout << num << '\n';
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