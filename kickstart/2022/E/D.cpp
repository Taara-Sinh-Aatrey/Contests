/**
 *    author:  Taara Sinh Aatrey
 *    created: 21.08.2022 09:57:31
**/

#include "bits/stdc++.h"

using namespace std;

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int dr[] = {-1, 0, 0, 1};
const int dc[] = {0, 1, -1, 0};

int64_t dp[1024][21][10][10];

int main() {
#define int int64_t
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n, p, m, R, C;
        cin >> n >> p >> m >> R >> C, --R, --C;
        vector<pair<char, int>> toll(4);
        for (auto &[ch, num] : toll) {
            cin >> ch >> num;
        }
        const int inf = 1e18L + 5;
        const pair<int, int> init = {-1, -1};
        for (int mask = 0; mask < 1 << p; mask++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    for (int d = 0; d <= m; d++) {
                        dp[mask][d][r][c] = -inf;
                    }
                }
            }
        }
        vector<vector<pair<int, int>>> pizza(n, vector<pair<int, int>>(n, init));
        for (int i = 0; i < p; i++) {
            int x, y, coins;
            cin >> x >> y >> coins, --x, --y;
            pizza[x][y] = {coins, i};
        }
        // vector<vector<vector<int>>> dp(1 << p, vector<vector<int>>(n, vector<int>(n, -inf)));
        dp[0][0][R][C] = 0;
        queue<array<int, 5>> q;
        q.push({R, C, 0, 0, 0});
        auto e = [&] (int r, int c) {
            return 0 <= r && r < n && 0 <= c && c < n;
        };
        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            auto [r, c, d, mask, coins] = q.front();
            q.pop();
            if (dp[mask][d][r][c] > coins) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (!e(nr, nc)) continue;
                auto fun = [&] (int pizza_coins, int new_mask) {
                    auto [ch, cns] = toll[dir];
                    int new_coins = 0;
                    if (ch == '+') {
                        new_coins = coins + cns;
                    }
                    else if (ch == '-') {
                        new_coins = coins - cns;
                    }
                    else if (ch == '*') {
                        new_coins = coins * cns;
                    }
                    else if (ch == '/') {
                        new_coins = coins / cns;
                        while (new_coins * cns > coins) {
                            new_coins--;
                        }
                    }
                    new_coins += pizza_coins;
                    if (d + 1 <= m && new_coins > dp[new_mask][d + 1][nr][nc]) {
                        dp[new_mask][d + 1][nr][nc] = new_coins;
                        // dbg(dir, r, c, coins, nr, nc, new_coins);
                        q.push({nr, nc, d + 1, new_mask, new_coins});
                    }
                };
                int pizza_coins = 0;
                int new_mask = mask;
                fun(pizza_coins, new_mask);
                
                if (pizza[nr][nc] != init && (~mask >> pizza[nr][nc].second & 1)) {
                    auto [cns, i] = pizza[nr][nc];
                    new_mask |= 1LL << i;
                    pizza_coins += cns;
                    fun(pizza_coins, new_mask);
                }
            }
        }
        int ans = -inf;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                for (int d = 0; d <= m; d++) {
                    ans = max(ans, dp[(1 << p) - 1][d][r][c]);
                }
            }
        }
        if (ans <= -inf) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        cout << ans << '\n';
    }
    return 0;
#undef int
}

/*
2 R _
3 _ 1
_ 4 _
*/