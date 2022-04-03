#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef LOCAL
#include "debug.hpp"
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, m;
    scan(n, m);
    vector<string> s(n);
    scan(s);
    string cmd;
    scan(cmd);
    int k = cmd.size();
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, -1, 0, 1};
    const char dd[] = {'U', 'L', 'D', 'R'};
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, inf)));
    pair<int, int> beg, end;
    int d[n][m][n][m];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    d[r][c][i][j] = inf;
                }
            }
            queue<pair<int, int>> q;
            q.emplace(r, c);
            d[r][c][r][c] = 0;
            while (!q.empty()) {
                auto [i, j] = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir], nj = j + dy[dir];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] != '#' && d[r][c][ni][nj] > d[r][c][i][j] + 1) {
                        d[r][c][ni][nj] = d[r][c][i][j] + 1;
                        q.emplace(ni, nj);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'R') {
                dp[i][j][0] = 0;
            }
            else if (s[i][j] == 'E') {
                end = {i, j};
            }
        }
    }
    for (int x = 0; x < k; x++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                amin(dp[i][j][x + 1], dp[i][j][x] + 1);
                if (s[i][j] == '#')
                    continue;
                char ch = cmd[x];
                int dir = 0;
                while (dd[dir] != ch)
                    dir++;
                int ni = i + dx[dir], nj = j + dy[dir];
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] != '#') {
                    amin(dp[ni][nj][x + 1], dp[i][j][x]);
                }
                else {
                    amin(dp[i][j][x + 1], dp[i][j][x]);
                }
                
                // let's try to add sth
                // dir = 0;
                // while (dir < 4) {
                //     ni = i + dx[dir], nj = j + dy[dir];
                //     if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] != '#') {
                //         amin(dp[ni][nj][x + 1], dp[i][j][x + 1] + 1);
                //     }
                //     dir++;
                // }
                for (ni = 0; ni < n; ni++) {
                    for (nj = 0; nj < m; nj++) {
                        amin(dp[ni][nj][x + 1], dp[i][j][x + 1] + d[i][j][ni][nj]);
                    }
                }
            }
        }
        // if (true) {
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < m; j++) {
        //             cout << dp[i][j][x + 1] << " ";
        //         }
        //         print();
        //     }
        // }
    }
    int ans = inf;
    for (int x = 0; x <= k; x++) {
        amin(ans, dp[end.first][end.second][x]);
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}