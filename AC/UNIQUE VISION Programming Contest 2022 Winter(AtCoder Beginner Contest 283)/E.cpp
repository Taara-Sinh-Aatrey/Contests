/**
 *    author:  Taara Sinh Aatrey
 *    created: 26.12.2022 03:12:21
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto e = [&] (int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;    
    };
    auto check = [&] (int r) {
        for (int c = 0; c < m; c++) {
            bool ok = false;
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dx[dir], nc = c + dy[dir];
                if (e(nr, nc) && a[nr][nc] == a[r][c]) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return false;
            }
        }
        return true;
    };
    auto toggle = [&] (int r) {
        if (r < 0 || r >= n) return;
        for (int c = 0; c < m; c++) {
            a[r][c] ^= 1;
        }
    };
    const int inf = 1e18L + 5;
    const array<array<int, 2>, 2> init = {array<int, 2>{inf, inf}, array<int, 2>{inf, inf}};
    array<array<int, 2>, 2> dp;
    for (int i = 0; i < n; i++) {
        array<array<int, 2>, 2> ndp = init;
        for (int j = 0; j < 2; j++) {
            if (j == 1) toggle(i - 1);
            for (int k = 0; k < 2; k++) {
                if (k == 1) toggle(i);
                for (int l = 0; l < 2; l++) {
                    // dp[j][k] -> ndp[k][l]
                    if (l == 1) toggle(i + 1);
                    if (check(i)) {
                        ndp[k][l] = min(ndp[k][l], dp[j][k] * (i != 0) + (k == 1));
                    }
                    if (l == 1) toggle(i + 1);
                }
                if (k == 1) toggle(i);
            }
            if (j == 1) toggle(i - 1);
        }
        swap(dp, ndp);
    }
    int ans = min(dp[0][0], dp[1][0]);
    if (ans >= inf) ans = -1;
    cout << ans;
    return 0;
}