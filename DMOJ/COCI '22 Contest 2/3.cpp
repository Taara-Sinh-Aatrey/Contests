/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.12.2022 19:39:20
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    const int inf = 1e13L + 5;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 0; i < k; i++) {
        int val = rand(0, inf);
        for (int j = 0; j < 2; j++) {
            int r, c;
            cin >> r >> c;
            a[r][c] += val * (j == 0 ? 1 : -1);
        }
    }
    int ans = 0;
    for (int r1 = 0; r1 <= n; r1++) {
        vector<int> vals(m + 1);
        for (int r2 = r1; r2 <= n; r2++) {
            for (int c = 0; c <= m; c++) {
                vals[c] += a[r2][c];
            }
            if (r2 == r1) continue;
            map<int, int> cnt;
            int pref = 0, prev_pref = 0;
            for (int c = 0; c <= m; c++) {
                prev_pref = pref;
                pref += vals[c];
                ans += cnt[pref];
                cnt[prev_pref]++;
            }
        }
    }
    cout << ans;
    return 0;
}