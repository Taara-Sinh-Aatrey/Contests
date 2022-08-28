/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 23:54:10
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, -1, 0, 1};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 3, m;
    cin >> m;
    vector<string> s(n);
    queue<pair<int, int>> q;
    vector<vector<bool>> reach(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i][0] == '0') {
            q.emplace(i, 0);
            reach[i][0] = true;
        }
    }
    bool ok = false;
    while (!q.empty() && !ok) {
        auto [r, c] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && s[nr][nc] == '0' && !reach[nr][nc]) {
                reach[nr][nc] = true;
                q.emplace(nr, nc);
                if (nc == m - 1) {
                    ok = true;
                }
            }
        }
    }
    cout << (ok ? "Solvable!" : "Unsolvable!") << '\n';
    return 0;
}