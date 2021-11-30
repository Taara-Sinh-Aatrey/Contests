#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
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
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<bool>> act(n, vector<bool>(m));
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, pair(-1, -1)));
    vector<vector<int>> d(n, vector<int>(m, 1));
    auto e = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;  
    };
    function<void(int, int)> dfs = [&](int r, int c) {
        vis[r][c] = true;
        act[r][c] = true;
        int nr = r, nc = c;
        auto &ch = s[r][c];
        if (ch == 'L')
            nc--;
        else if (ch == 'R')
            nc++;
        else if (ch == 'U')
            nr--;
        else
            nr++;
        if (e(nr, nc)) {
            if (!vis[nr][nc]) {
                p[nr][nc] = {r, c};
                dfs(nr, nc);
            }
            if (!act[nr][nc]) {
                d[r][c] += d[nr][nc];                
            }
            else {
                int x = r, y = c;
                int cnt = 0;
                do {
                    cnt++;
                    auto pr = p[x][y];
                    x = pr.first;
                    y = pr.second;
                } while (!(x == r && y == c));
            }
        }
        else if ()
        act[r][c] = false;
    };
    vector<int> ans(3);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (vis[r][c]) continue;
            dfs(r, c);
            ans = max(ans, {d[r][c], r + 1, c + 1});
        }
    }
    print(ans[1], ans[2], ans[0]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}