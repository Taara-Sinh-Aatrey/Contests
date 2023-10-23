/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 01:37:18
**/

// 0f16c17272fa3f3df8f99ff403a98366

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
        cout << "Case #" << tt << ": \n";
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n - 1; i++) {
            int mask = i;
            string t = string(1, s[0] ^ '.' ^ '-');
            for (int bit = 0; bit < 9; bit++) {
                t += char((mask >> bit & 1) ? '.' : '-');
            }
            cout << t << '\n';
        }
    }
    return 0;
}