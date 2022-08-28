/**
 *    author:  Taara Sinh Aatrey
 *    created: 27.08.2022 23:29:49
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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> pref(m, n), suff(m, -1);
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && t[i] != s[j]) j++;
        if (j == n) break;
        pref[i] = j++;
    }
    j = n - 1;
    for (int i = m - 1; i >= 0; i--) {
        while (j >= 0 && t[i] != s[j]) j--;
        if (j == -1) break;
        suff[i] = j--;
    }
    int ans = 0;
    for (int i = 0; i + 1 < m; i++) {
        if (pref[i] < n && suff[i + 1] >= 0)
            ans = max(ans, suff[i + 1] - pref[i]);
    }
    cout << ans << '\n';
    return 0;
}