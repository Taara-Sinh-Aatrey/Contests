/**
 *    author:  Taara Sinh Aatrey
 *    created: 25.12.2022 16:38:01
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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    map<pair<int, int>, int> id;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            int cnt = 0;
            for (int c1 : {c - 1, c + 1}) {
                cnt += c1 >= 0 && c1 < w && a[r][c] == a[r][c1];
            }
            if (cnt == 0)
                id[{r, c}] = id.size();
            if (cnt > 0) {
                continue;
            }
            for (int c1 : {c - 1, c + 1}) {
                cnt += c1 >= 0 && c1 < w && a[r][c] == a[r][c1];
            }
        }
    }
    int n = id.size();
    vector<vector<int>> g(2 * n);
    for (auto &[p, u] : id) {
        auto &[r, c] = p;
        int cnt = 0;
        for (int c1 : {c - 1, c + 1}) {
    }
    return 0;
}