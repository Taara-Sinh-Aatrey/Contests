#include "bits/stdc++.h"
#include <pthread.h>
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "["; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "]"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename Head> void dbg_out(string var, const Head &H) { cerr << var << " = " << H << endl; } template <typename Head, typename ...Tail> void dbg_out(string var, const Head &H, const Tail &...T) { for (int i = 0, b = 0; i < int(var.size()); i++) { if (var[i] == '(' || var[i] == '{') { b++; } else if (var[i] == ')' || var[i] == '}') { b--; } else if (var[i] == ',' && b == 0) { cerr << var.substr(0, i) << " = " << H << " | "; dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...); break; } } }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
#ifndef ONLINE_JUDGE
#define dbg(...) debug = true, dbg_out(#__VA_ARGS__, __VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

#define int int64_t
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 2e5 + 5;

void solve() {
    int n, m;
    scan(n, m);
    vector<vector<int>> can(n, vector<int>(m));
    for (int i = 0; i < n * m; i++) {
        can[i % n][i % m] = 1;
    }
    queue<pair<int, int>> q;
    vector<vector<int>> a(2);
    a[0].resize(n);
    a[1].resize(m);
    for (int i = 0; i < 2; i++) {
        int sz;
        scan(sz);
        for (int j = 0; j < sz; j++) {
            int x;
            scan(x);
            q.emplace(i, x);
            a[i][x] = 1;
        }
    }
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (i == 0) {
            for (int k = 0; k < m; k++) {
                if (a[1][k] == 1 || !can[j][k]) continue;
                a[1][k] = 1;
                q.emplace(1, k);
            }
        }
        else {
            for (int k = 0; k < n; k++) {
                if (a[0][k] == 1 || !can[k][j]) continue;
                a[0][k] = 1;
                q.emplace(0, k);
            }
        }
    }
    bool ok = true;
    for (int j = 0; j < n; j++) {
        ok = ok & a[0][j];
    }
    for (int j = 0; j < m; j++) {
        ok = ok & a[1][j];
    }
    print(ok ? "Yes" : "No");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}