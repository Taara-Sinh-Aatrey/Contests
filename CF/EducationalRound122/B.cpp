#include "bits/stdc++.h"
using namespace std;

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int c0 = count(s.begin(), s.end(), '0');
    int c1 = n - c0;
    cout << (min(c0, c1) - (c0 == c1)) << '\n';
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