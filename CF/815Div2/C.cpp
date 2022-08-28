/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 22:29:48
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
        int n, m;
        cin >> n >> m;
        string pv;
        int ones = 0, z = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                ones += s[j] == '1';
                if (i == 0) continue;
                if (j - 1 >= 0) {
                    z = max(z, '1' - pv[j - 1] + '1' - pv[j] + '1' - s[j]);
                    z = max(z, '1' - s[j - 1] + '1' - pv[j] + '1' - s[j]);
                }
                if (j + 1 < m) {
                    z = max(z, '1' - pv[j + 1] + '1' - pv[j] + '1' - s[j]);
                    z = max(z, '1' - s[j + 1] + '1' - pv[j] + '1' - s[j]);
                }
            }
            swap(pv, s);
        }
        z = min(z, 2);
        cout << ones - (2 - z) << '\n';
    }
    return 0;
}