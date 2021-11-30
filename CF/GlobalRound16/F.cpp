#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
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
    vector<int> a(n);
    scan(a);
    sort(a.begin(), a.end());
    vector<vector<pair<int, int>>> s(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        scan(x, y);
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) {
            s[n].emplace_back(x, y);
            continue;
        }
        int id = it - a.begin();
        if (x <= a[id] && y >= a[id]) continue;
        s[id].emplace_back(x, y);
    }
    int dist = 0;
    for (auto& p : s[0]) {
        dist = max(dist, a[0] - p.second);
    }
    int dp1 = dist, dp2 = dist * 2;
    vector<int> pref, suf;
    for (int i = 1; i < n; i++) {
        sort(s[i].begin(), s[i].end());
        int sz = (int) s[i].size();
        suf.resize(sz + 1);
        suf[sz] = 0;
        for (int j = sz - 1; j >= 0; j--) {
            suf[j] = max(suf[j + 1], a[i] - s[i][j].second);
        }
        pref.resize(sz + 1);
        pref[0] = 0;
        for (int j = 0; j < sz; j++) {
            pref[j + 1] = max(pref[j], s[i][j].first - a[i - 1]);
        }
        int new_dp1 = inf, new_dp2 = inf;
        for (int j = 0; j <= sz; j++) {
            int x = pref[j];
            int y = suf[j];
            new_dp1 = min({new_dp1, dp2 + x * 1 + y * 1, dp1 + x * 2 + y * 1});
            new_dp2 = min({new_dp2, dp2 + x * 1 + y * 2, dp1 + x * 2 + y * 2});
        }
        dp1 = new_dp1;
        dp2 = new_dp2;
    }
    dist = 0;
    for (auto& p : s[n]) {
        dist = max(dist, p.first - a[n - 1]);
    }
    print(min(dp1 + dist * 2, dp2 + dist * 1));
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