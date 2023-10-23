/**
 *    author:  Taara Sinh Aatrey
 *    created: 03.09.2022 17:34:09
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
    string s;
    cin >> s;
    vector<int> cols = {3, 2, 4, 1, 3, 5, 0, 2, 4, 6};
    int m = 7;
    vector<bool> all(m, true);
    for (int i = 0; i < 10; i++) {
        all[cols[i]] = all[cols[i]] & (s[i] == '0' ? true : false);
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (!all[i]) continue;
        bool pref = false;
        for (int j = 0; j < i; j++) {
            pref |= !all[j];
        }
        bool suff = false;
        for (int j = i + 1; j < m; j++) {
            suff |= !all[j];
        }
        cnt += (pref && suff) ? 1 : 0;    
    }
    cout << (cnt >= 1 && s[0] == '0' ? "Yes" : "No") << '\n';
    return 0;
}