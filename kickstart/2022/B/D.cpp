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
    n *= 2;
    m *= 2;
    vector<string> s(n, string(m, '?'));
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < m; j += 2) {
            scan(s[i][j]);
            s[i][j + 1] = s[i + 1][j] = s[i + 1][j + 1] = s[i][j];
        }
    }
    string ans = "";
    for (int i = 0; i < n - 1; i++) {
        ans += 'S';
    }
    ans += 'E';
    for (int i = n - 1; i >= 0;) {
        int beg = i % 2 == 1 ? 1 : m - 1;
        int end = i % 2 == 1 ? m - 1 : 1;
        char ch = i % 2 == 1 ? 'E' : 'W';
        int delta = i % 2 == 1 ? +1 : -1;
        if (i % 4 == 3) {
            assert(beg == 1);
            if (beg == 1) {
                ans += "NN";
                if (beg + 1 < end)
                    ans += ch;
                beg += delta;
                while (beg < end) {
                    if (s[i][beg] == '#') {
                        ans += ch;
                        if (beg + 2 < end)
                            ans += ch;
                    }
                    else {
                        ans += "SS";
                        ans += ch;
                        ans += "NN";
                        if (beg + 2 < end)
                            ans += ch;
                    }
                    beg += 2;
                }
                ans += "N";
            }
            ans += string(m - 2, 'W');
            if (i != 3)
                ans += "N";
            i -= 4;
        }
        else {
            ans += string(m - 2, 'E');
            ans += "N";
            ans += string(m - 2, 'W');
            if (i != 1)
                ans += "N";
            i -= 2;
        }
    }
    ans += 'W';
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}