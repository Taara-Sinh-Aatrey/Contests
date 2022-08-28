/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.08.2022 20:16:35
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        int64_t n, k, b;
        int64_t s;
        cin >> n >> k >> b >> s;
        int64_t mx = s / k;
        int64_t mn = max<int64_t>(0, s - (k - 1) * (n - 1)) / k;
        if (b < mn || b > mx) {
            cout << -1 << '\n';
            continue;
        }
        vector<int64_t> a(n);
        a[0] = s;
        for (int i = 1; i < n; i++) {
            if (a[0] / k > b && a[0] >= k - 1) {
                a[0] -= k - 1;
                a[i] += k - 1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        assert(a[0] / k == b);
    }
    return 0;
}