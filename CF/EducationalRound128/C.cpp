#include "bits/stdc++.h"
#include <cinttypes>
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
    int n = s.size();
    int ZERO = count(s.begin(), s.end(), '0');
    int lo = 0, hi = n;
    vector<int> suff{0};
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            c++;
        }
        else {
            suff.emplace_back(c);
        }
    }
    auto check = [&] (int k) {
        int zl = 0;
        int ol = 0;
        int zr = suff[min<int>(suff.size() - 1, k + 1 - ol)];
        if (ZERO - zl - zr <= k) {
            return true;
        }
        for (int i = 0; i < n; i++) {
            if (ol > k) {
                break;
            }
            if (s[i] == '1') {
                ol++;
            }
            else {
                zl++;
            }
            zr = suff[min<int>(suff.size() - 1, k + 1 - ol)];
            if (ZERO - zl - zr <= k) {
                return true;
            }
        }
        return false;
    };
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    print(lo);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}