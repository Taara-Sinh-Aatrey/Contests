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
    vector<vector<int>> a(n, vector<int>(m));
    scan(a);
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&a](int x, int y){ return a[x][0] > a[y][0]; });
    vector<vector<int>> mxl(n, vector<int>(m, -inf));
    vector<vector<int>> mnr(n, vector<int>(m, inf));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            mxl[i][j] = a[ord[i]][j];
            if (i < n - 1) 
                amax(mxl[i][j], mxl[i + 1][j]);
            if (j > 0) 
                amax(mxl[i][j], mxl[i][j - 1]);
        }
    }
    for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j){
        mnr[i][j] = a[ord[i]][j];
        if (i < n - 1) amin(mnr[i][j], mnr[i + 1][j]);
        if (j < m - 1) amin(mnr[i][j], mnr[i][j + 1]);
    }
    vector<int> mnl(m, inf), mxr(m, -inf);
    pair<int, int> ans(-1, -1);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            amin(mnl[j], a[ord[i]][j]);
            if (j > 0)
                amin(mnl[j], mnl[j - 1]);
        }
        for (int j = m - 1; j >= 0; j--) {
            amax(mxr[j], a[ord[i]][j]);
            if (j < m - 1)
                amax(mxr[j], mxr[j + 1]);
        }
        for (int j = 0; j < m - 1; j++)
            if (mnl[j] > mxl[i + 1][j] && mxr[j + 1] < mnr[i + 1][j + 1])
                ans = {i, j};
    }
    if (ans.first == -1){
        print("NO");
        return;
    }
    print("YES");
    string s(n, '.');
    for (int i = 0; i < n; i++) 
        s[ord[i]] = i <= ans.first ? 'R' : 'B';
    print(s, ans.second + 1);
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