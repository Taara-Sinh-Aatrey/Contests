/**
 *    author:  Taara Sinh Aatrey
 *    created: 11.09.2022 15:17:58
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
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        if (k == 0) {
            cout << (a == b ? "YES" : "NO") << '\n';
            continue;
        }
        if (n == 2) {
            cout << ((a == b) == (k % 2 == 0) ? "YES" : "NO") << '\n';
            continue;
        }
        if (k == 1 && a == b) {
            cout << "NO\n";
            continue;
        }
        int j = 0;
        while (j < n && b[j] != a[0]) j++;
        bool ok = true;
        for (int i = 0; i < n; i++, j = (j + 1) % n) {
            ok &= a[i] == b[j];
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}