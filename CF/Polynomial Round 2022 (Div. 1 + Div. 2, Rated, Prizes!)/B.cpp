/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.12.2022 02:18:15
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        bool ok = true;
        int q = n / k, r = n % k;
        for (int i = 0; i < m; i++) {
            int lim = q + (i < r ? 1 : 0);
            ok &= a[i] <= lim;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}