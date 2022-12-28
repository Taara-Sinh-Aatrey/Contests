/**
 *    author:  Taara Sinh Aatrey
 *    created: 20.12.2022 08:03:11
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
        vector<vector<int>> a(2, vector<int>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> a[i][j];
            }
        }
        bool any = false;
        for (int rep = 0; rep < 4; rep++) {
            bool ok = true;
            for (int i = 0; i < 2; i++) {
                ok &= a[i][0] < a[i][1];
                ok &= a[0][i] < a[1][i];
            }
            any |= ok;
            tie(a[0][0], a[0][1], a[1][0], a[1][1]) = make_tuple(a[1][0], a[0][0], a[1][1], a[0][1]);
        }
        cout << (any ? "YES" : "NO") << '\n';
    }
    return 0;
}