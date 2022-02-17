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
    string s;
    scan(s);
    int ans = inf;
    auto check = [&] (string x, int ops) {
        int num = stoll(x);
        int c = 0;
        while (x[c] == '0')
            c++;
        ops += c;
        if (num % 25 == 0)
            amin(ans, ops);
    };
    auto Insert = [&] (string x, int i, int j) {
        string y = x;
        char ch = y[i];
        y.erase(y.begin() + i);
        y.insert(y.begin() + j, ch);
        return y;
    };
    check(s, 0);
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string x = Insert(s, i, n - 1);
            check(x, n - 1 - i);
            if (x[0] != '0') {
                x = Insert(x, j, n - 1);
                check(x, n - 1 - i + n - 1 - j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (n < 2)
                continue;
            string x = Insert(s, i, n - 2);
            check(x, abs(n - 2 - i));
            if (x[0] != '0') {
                x = Insert(x, j, n - 1);
                check(x, abs(n - 2 - i) + abs(n - 1 - j));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (n < 2)
                continue;
            string x = Insert(s, i, n - 1);
            check(x, n - 1 - i);
            if (x[0] != '0') {
                x = Insert(x, j, n - 2);
                check(x, abs(n - 1 - i) + abs(n - 2 - j));
            }
        }
    }
    print(ans >= inf ? -1 : ans);
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