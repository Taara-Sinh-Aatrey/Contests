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
    int n, l, F;
    scan(n, l, F);
    vector<string> a(n);
    scan(a);
    vector<int> dp(F + 1, 0);
    for (int it = 0; it < n; it++) {
        int i = 0, j = l - 1;
        auto &s = a[it];
        while (i < l && s[i] == '0') i++;
        while (j >= 0 && s[j] == '0') j--;
        vector<int> L(F + 1), R(F + 1);
        L[0] = i;
        for (int f = 1; f <= F; f++) {
            i++;
            while (i < l && s[i] == '0') i++;
            L[f] = i;
        }
        R[0] = j;
        for (int f = 1; f <= F; f++) {
            j--;
            while (j >= 0 && s[j] == '0') j--;
            R[f] = j;
        }
        vector<int> my(F + 1, inf);
        for (int x = 0; x <= F; x++) {
            for (int y = 0; y + x <= F; y++) {
                my[x + y] = min(my[x + y], max<int>(0, R[x] - L[y] + 1));
            }
        }
        vector<int> ndp(F + 1, inf);
        for (int x = 0; x <= F; x++) {
            for (int y = 0; y + x <= F; y++) {
                ndp[x + y] = min(ndp[x + y], dp[x] + my[y]);
            }
        }
        swap(dp, ndp);
    }
    print(*min_element(dp.begin(), dp.end()));
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