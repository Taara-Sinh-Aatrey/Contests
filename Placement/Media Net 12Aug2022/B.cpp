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

vector<int> solve(int n, int m, const vector<string> &a) {
#define ld long double
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    vector<vector<ld>> ans(n, vector<ld>(m, 0));
    auto bfs = [&] (int y) {
        int x = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<ld>> prob(n, vector<ld>(m, 0));
        prob[x][y] = 1;
        queue<pair<int, int>> q;
        q.emplace(x, y);
        vis[x][y] = true;
        auto e = [&] (int i, int j) {
            return 0 <= i && i < n && 0 <= j && j < m;    
        };
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];
                if (!e(ni, nj) || a[ni][nj] == 'X') continue;
                prob[ni][nj] += prob[i][j] / 4;
                if (!vis[ni][nj] && a[ni][nj] != 'C') {
                    q.emplace(ni, nj);
                }
                vis[ni][nj] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] += prob[i][j];
            }
        }
    };
    int cnt = 0;
    for (int j = 0; j < m; j++) {
        if (a[0][j] == '.') {
            bfs(j);
            cnt++;
        }
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'C') {
                ret.emplace_back(floor(1e5 * ans[i][j] / cnt));
            }
        }
    }
    return ret;
}

signed main() {
    print(solve(2, 3, {"X.X", "C.C"}));
    print(solve(5, 4, {"....", ".XX.", "....", "C..C", "XCCX"}));
    return 0;
}