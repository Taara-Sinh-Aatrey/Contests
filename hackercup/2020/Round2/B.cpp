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
    int n;
    long double p;
    cin >> n >> p;
    vector<long double> q(n + 1);
    for (int i = 1; i < (int) q.size(); i++) {
        long long pairs = i * (i - 1) / 2;
        q[i] = (long double) 1.0 / (long double) pairs;
    }
    vector<vector<long double>> f(n, vector<long double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            int cnt = i + j + 1;
            if (cnt == 1) {
                continue;
            }
            if (i > 0 && j > 0) {
                f[i][j] += i * j * (f[i][j - 1] * p + f[i - 1][j] * (1 - p));
            }
            if (i > 1) {
                f[i][j] += i * (i - 1) / 2 * f[i - 1][j];
            }
            if (j > 1) {
                f[i][j] += j * (j - 1) / 2 * f[i][j - 1];
            }
            if (i > 0) {
                f[i][j] += i * f[i - 1][j] * (1 - p);
            }
            if (j > 0) {
                f[i][j] += j * f[i][j - 1] * p;
            }
            f[i][j] *= q[cnt];
            f[i][j] += 1;
        }
    }
    cout << fixed << setprecision(17);
    for (int i = 0; i < n; i++) {
        cout << f[n - 1 - i][i] << '\n';
    }
}

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}