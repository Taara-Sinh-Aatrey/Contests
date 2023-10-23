/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.08.2022 22:41:06
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
        int r, c;
        cin >> r >> c;
        vector<string> s(r);
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            cin >> s[i];
            cnt += count(s[i].begin(), s[i].end(), '^');
        }
        if (cnt > 0 && (r == 1 || c == 1)) {
            cout << "Impossible" << '\n';
            continue;
        }
        cout << "Possible" << '\n';
        for (int i = 0; i < r; i++) {
            if (cnt != 0) {
                s[i] = string(c, '^');
            }
            cout << s[i] << '\n';
        }
    }
    return 0;
}