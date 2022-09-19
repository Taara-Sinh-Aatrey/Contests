/**
 *    author:  Taara Sinh Aatrey
 *    created: 18.09.2022 22:31:30
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
        cout << "Case #" << caseno << ": ";
        int n;
        cin >> n;
        vector<string> c(n);
        vector<int> d(n), u(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i] >> d[i] >> u[i];
        }
        vector<int> ord1(n);
        iota(ord1.begin(), ord1.end(), 0);
        sort(ord1.begin(), ord1.end(), [&] (auto &i, auto &j) {
            if (c[i] == c[j]) {
                return u[i] < u[j];
            }
            return c[i] < c[j];
        });
        vector<int> ord2(n);
        iota(ord2.begin(), ord2.end(), 0);
        sort(ord2.begin(), ord2.end(), [&] (auto &i, auto &j) {
            if (d[i] == d[j]) {
                return u[i] < u[j];
            }
            return d[i] < d[j];
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += ord1[i] == ord2[i];
        }
        cout << ans << '\n';
    }
    return 0;
}