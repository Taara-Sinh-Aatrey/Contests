#include "bits/stdc++.h"
#include <algorithm>
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
    int n, k;
    scan(n, k);
    vector<int> a(n);
    scan(a);
    // function<void(int, int, int, vector<int>&)> recurse = [&] (int lo, int hi, int ops, vector<int> &best) -> void {
    //     if (lo > hi) {
    //         return;
    //     }
    //     vector<int> order(hi - lo + 1);
    //     iota(order.begin(), order.end(), lo);
    //     sort(order.begin(), order.end(), [&] (auto &x, auto &y) {
    //         return a[x] < a[y];
    //     });
    //     for (auto &i : order) {
    //         int mn_ops = min(i - lo, hi - i + 1);
    //         if (i - lo <= ops) {
    //             vector<int> cur;
    //             recurse(i + 1, hi, ops - (i - lo), cur);
    //             if (best.empty() || cur < best) {
    //                 best = cur;
    //             }
    //         }
    //         if (hi - i + 1 <= ops) {
    //             vector<int> cur;
    //             recurse(lo, i - 1, ops - (hi - i + 1), cur);
    //             if (best.empty() || cur < best) {
    //                 best = cur;
    //             }
    //         }
    //         if (mn_ops <= ops) {
    //             best.insert(best.begin(), a[i]);
    //             dbg(lo, hi, ops, best, 1);
    //             return;
    //         }
    //     }
    //     vector<int> x = vector<int>(a.begin() + lo, a.begin() + hi + 1);
    //     best = x;
    //     dbg(lo, hi, ops, best);
    // };
    vector<int> ans;
    // recurse(0, n - 1, k, ans);
    auto solve = [&] (vector<int> arr, int start, int from, int ops) {
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&] (auto &x, auto &y) {
            return arr[x] < arr[y];
        });
        vector<int> vec;
        for (int i = 0; i < from; i++) {
            vec.emplace_back(arr[i]);
        }
        int idx = from;
        for (auto &i : order) {
            if (i < idx) {
                continue;
            }
            int req = i - start;
            if (req <= ops) {
                ops -= req;
                vec.emplace_back(arr[i]);
                idx = i + 1;
            }
        }
        return vec;
    };
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (auto &x, auto &y) {
        return a[x] < a[y];
    });
    for (auto &i : order) {
        int mn_ops = min(i, n - i);
        if (i <= k) {
            vector<int> cur = solve(a, 0, 0, k);
            if (ans.empty() || cur < ans) {
                ans = cur;
            }
            dbg(cur);
        }
        if (n - i <= k) {
            rotate(a.begin(), a.begin() + i, a.end());
            vector<int> cur = solve(a, n - i, 1, k - (n - i));
            if (ans.empty() || cur < ans) {
                ans = cur;
            }
            dbg(a, n - i, k - (n - i));
        }
        if (mn_ops <= k) {
            break;
        }
    }
    print(ans);
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