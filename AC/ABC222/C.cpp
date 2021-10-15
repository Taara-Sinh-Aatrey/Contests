#include "bits/stdc++.h"
#include <utility>
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
    n *= 2;
    vector<string> a(n);
    scan(a);
    vector<int> rank;
    for (int i = 0; i < n; i++) {
        rank.emplace_back(i);
    }
    vector<int> win(n, 0);
    for (int j = 0; j < m; j++) {
        for (int it = 0; it < n; it += 2) {
            auto p1 = rank[it], p2 = rank[it + 1];
            char c1 = a[p1][j], c2 = a[p2][j];
            if (c1 == 'G' && c2 == 'C') {
                win[p1]++;
            }
            else if (c1 == 'C' && c2 == 'P') {
                win[p1]++;
            }
            else if (c1 == 'P' && c2 == 'G') {
                win[p1]++;
            }
            else if (c1 != c2) win[p2]++;
        }
        sort(rank.begin(), rank.end(), [&](auto &x, auto& y) {
            if (win[x] == win[y]) {
                return x < y;
            }
            return win[x] > win[y];
        });
    }
    for (auto& x : rank) print(x + 1);
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