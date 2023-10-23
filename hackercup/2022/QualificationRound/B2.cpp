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
    // #ifdef AATREY_DEBUG
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        const int dr[] = {-1, 0, 1, 0};
        const int dc[] = {0, -1, 0, 1};
        queue<pair<int, int>> q;
        vector<vector<bool>> invalid(n, vector<bool>(m));
        auto e = [&] (int r, int c) {
            return 0 <= r && r < n && 0 <= c && c < m && s[r][c] != '#' && !invalid[r][c];  
        };
        auto is_valid = [&] (int r, int c) {
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir], nc = c + dc[dir];
                cnt += e(nr, nc);
            }
            return cnt >= 2;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!is_valid(i, j)) {
                    invalid[i][j] = true;
                    q.emplace(i, j);
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (e(nr, nc) && !invalid[nr][nc] && !is_valid(nr, nc)) {
                    invalid[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == '^' && invalid[i][j]) {
                    ok = false;
                    break;
                }
                if (s[i][j] != '#' && !invalid[i][j]) {
                    s[i][j] = '^';
                }
            }
        }
        if (!ok) {
            cout << "Impossible" << '\n';
            continue;
        }
        cout << "Possible" << '\n';
        for (int i = 0; i < n; i++) {
            cout << s[i] << '\n';
        }
    }
    return 0;
}