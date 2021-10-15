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
    scan(n);
    auto top_left = [&](vector<string> s) -> pair<int, int> {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i][j] == '#') {
                    return {i, j};
                }
            }
        }
        assert(false);
    };
    auto e = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < n;  
    };
    
    vector<string> s(n), t(n);
    scan(s, t);
    for(int rep = 0; rep < 4; rep++) {
        auto [si, sj] = top_left(s);
        auto [ti, tj] = top_left(t);
        auto z = s;
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                c1 += s[i][j] == '#';
                c2 += t[i][j] == '#';
                int ii = i + si - ti;
                int jj = j + sj - tj;
                if((e(ii, jj) && s[ii][jj] == t[i][j])) {
                    c1 -= s[ii][jj] == '#';
                    c2 -= t[i][j] == '#';
                }
                z[j][n - 1 - i] = s[i][j];
            }
        }
        s = z;
        if(c1 == 0 && c2 == 0) {
            print("Yes");
            return;
        }
    }
    print("No");
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