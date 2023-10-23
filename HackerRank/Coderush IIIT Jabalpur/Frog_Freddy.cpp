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
    int q, n;
    scan(q, n);
    string s;
    scan(s);
    int r, c;
    scan(r, c);
    q--;
    map<int, set<pair<int, int>>> xpy, xny;
    for (int i = 0; i < q; i++) {
        int x, y;
        scan(x, y);
        xpy[x + y].emplace(x, y);
        xny[x - y].emplace(x, y);
    }
    auto update = [&] (set<pair<int, int>>::iterator it) {
        r = it->first;
        c = it->second;
        xny[r + c].erase({r, c});
        xpy[r + c].erase({r, c});
    };
    for (auto &ch : s) {
        if (ch == 'A' || ch == 'D') {
            // xny
            int z = r - c;
            if (ch == 'A') {
                auto it = xny[z].upper_bound({r + 1, -inf});
                if (it != xny[z].end()) {
                    update(it);
                }
            }
            else {
                auto it = xny[z].lower_bound({r, -inf});
                if (it != xny[z].begin()) {
                    it = prev(it);
                    update(it);
                }
            }
        }
        else {
            int z = r + c;
            if (ch == 'B') {
                auto it = xpy[z].upper_bound({r + 1, -inf});
                if (it != xpy[z].end()) {
                    update(it);
                }
            }
            else {
                auto it = xpy[z].lower_bound({r, -inf});
                if (it != xpy[z].begin()) {
                    it = prev(it);
                    update(it);
                }
            }
        }
    }
    print(r, c);
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