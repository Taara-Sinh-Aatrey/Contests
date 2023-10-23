/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.10.2022 12:11:09
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
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    for (int it = 0; it < m; it++) {
        int sz;
        cin >> sz;
        vector<int> a(sz);
        for (int i = 0; i < sz; i++) {
            cin >> a[i], --a[i];
        }
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                cnt[a[i]][a[j]]++;
                cnt[a[j]][a[i]]++;
            }
        }
    }
    int mn = 1e18L + 5;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mn = min(mn, cnt[i][j]);
        }
    }
    cout << (mn != 0 ? "Yes" : "No") << '\n';
    return 0;
}