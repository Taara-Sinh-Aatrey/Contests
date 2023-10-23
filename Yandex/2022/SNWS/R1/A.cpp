#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
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
    int n, q;
    scan(n, q);
    vector<int> a(n);
    scan(a);
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        scan(l1, r1, l2, r2);
        --l1, --r1, --l2, --r2;
        if (r1 > r2 || (r1 == r2 && l1 < l2)) {
            swap(l1, l2);
            swap(r1, r2);
        }
        int n = r1 - l1 + 1 + r2 - l2 + 1;
        if (r1 < l2) {
            auto find = [&] (int x) {
                if (x <= r1 - l1 + 1) {
                    return a[l1 + x - 1];
                }
                x -= r1 - l1 + 1;
                return a[l2 + x - 1];
            };
            if (n % 2 == 0) {
                print((find(n / 2) + find(n / 2 + 1)) / 2.0);
            }
            else {
                print(find(n / 2 + 1));
            }
        }
        else if (l2 <= l1) {
            // full overlap
            // l2 l1-1
            // l1 r1
            // r1+1 r2
            auto find = [&] (int x) {
                if (x <= l1 - l2) {
                    return a[l2 + x - 1];
                }
                x -= l1 - l2;
                if (x <= 2 * (r1 - l1 + 1)) {
                    return a[l1 + (x - 1) / 2];
                }
                x -= 2 * (r1 - l1 + 1);
                return a[r1 + x];
            };
            if (n % 2 == 0) {
                print((find(n / 2) + find(n / 2 + 1)) / 2.0);
            }
            else {
                print(find(n / 2 + 1));
            }
        }
        else {
            // l1 l2-1
            // l2 r1
            // r1+1 r2
            auto find = [&] (int x) {
                if (x <= l2 - l1) {
                    return a[l1 + x - 1];
                }
                x -= l2 - l1;
                if (x <= 2 * (r1 - l2 + 1)) {
                    return a[l2 + (x - 1) / 2];
                }
                x -= 2 * (r1 - l2 + 1);
                return a[r1 + x];
            };
            if (n % 2 == 0) {
                print((find(n / 2) + find(n / 2 + 1)) / 2.0);
            }
            else {
                print(find(n / 2 + 1));
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    cout << fixed << setprecision(10);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}

/*
-2 -1 -1 0 0 1 1
*/