/**
 *    author:  Taara Sinh Aatrey
 *    created: 04.09.2022 20:01:38
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        if (s[0] == 'B') {
            cout << -1 << '\n';
            continue;
        }
        bool ok = true;
        int ans = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == 'B') {
                ok = false;
                break;
            }
            int nj = i;
            while (i < n && s[i] == 'R') {
                nj = max(nj, i + d[i]);
                i++;
            }
            int cnt = 0;
            for (int x = j + 1; x <= nj; x++) {
                cnt += s[x] == 'B';
                s[x] = 'R';
            }
            ans += !!cnt;
            j = nj;
        }
        cout << (ok ? ans : -1) << '\n';
    }
    return 0;
}