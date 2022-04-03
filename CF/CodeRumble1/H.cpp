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
    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, -1, 0, 1};
    auto e = [&] (int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m && s[r][c] != 'W';  
    };
    vector<vector<bool>> vis(n, vector<bool>(m));
    auto grid_bfs = [&] (const vector<pair<int, int>> &source, vector<vector<int>> &d) {
        d.assign(n, vector<int>(m, inf));
        queue<pair<int, int>> q;
        for (auto &[r, c] : source) {
            q.emplace(r, c);
            d[r][c] = 0;
            vis[r][c] = true;  
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir], nc = c  + dc[dir];
                if(e(nr, nc) && d[r][c] + 1 < d[nr][nc]) {
                    q.emplace(nr, nc);
                    s[nr][nc] = 'L';
                    vis[nr][nc] = true;
                    d[nr][nc] = d[r][c] + 1;
                }
            }    
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> d;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'L' && !vis[i][j]) {
                ans++;
                grid_bfs({{i, j}}, d);
            }
        }
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