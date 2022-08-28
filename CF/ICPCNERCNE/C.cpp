#include "bits/stdc++.h"
#include <algorithm>
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
    vector<array<int, 4>> ans;
    int best = inf;
    auto fun = [&] (vector<pair<int, int>> &a) {
        vector<array<int, 4>> vec;
        int sum = 0;
        for (int i = 1; i < 2; i++) {
            sum += abs(a[i].first - a[i - 1].first);
            sum += abs(a[i].second - a[i - 1].second);
            if (a[i - 1].first != a[i].first)
                vec.push_back({a[i - 1].first, a[i - 1].second, a[i].first, a[i - 1].second});
            if (a[i - 1].second != a[i].second)
                vec.push_back({a[i].first, a[i - 1].second, a[i].first, a[i].second});
        }
        
        int score = inf;
        vector<array<int, 4>> v;
        for (auto [x1, y1, x2, y2] : vec) {
            tie(x1, x2) = make_tuple(min(x1, x2), max(x1, x2));
            tie(y1, y2) = make_tuple(min(y1, y2), max(y1, y2));
            if (y1 == y2 && x1 <= a[2].first && a[2].first <= x2) {
                int sc = abs(a[2].second - y1);
                if (sc < score) {
                    score = sc;
                    v = {{a[2].first, y1, a[2].first, a[2].second}};
                }
            }
            if (x1 == x2 && y1 <= a[2].second && a[2].second <= y2) {
                int sc = abs(a[2].first - x1);
                if (sc < score) {
                    score = sc;
                    v = {{x1, a[2].second, a[2].first, a[2].second}};
                }
            }
            int sc = abs(x1 - a[2].first) + abs(y1 - a[2].second);
            if (sc < score) {
                score = sc;
                v = {{x1, y1, x1, a[2].second}, {x1, a[2].second, a[2].first, a[2].second}};
            }
            sc = abs(x2 - a[2].first) + abs(y2 - a[2].second);
            if (sc < score) {
                score = sc;
                v = {{x2, y2, x2, a[2].second}, {x2, a[2].second, a[2].first, a[2].second}};
            }
        }
        
        for (auto &z : v) {
            if (z[0] != z[2] || z[1] != z[3])
                vec.emplace_back(z);
        }
        sum += score;
        
        if (sum < best) {
            best = sum;
            ans = vec;
        }
    };
    vector<pair<int, int>> a(3);
    scan(a);
    // sort(a.begin(), a.end());
    // fun(a);
    // sort(a.begin(), a.end(), [&] (auto &x,  auto &y) {
    //     return x.second < y.second;
    // });
    // fun(a);
    sort(a.begin(), a.end());
    do {
        fun(a);
    } while (next_permutation(a.begin(), a.end()));
    print(ans.size());
    for (auto &x : ans)
        print(x);
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