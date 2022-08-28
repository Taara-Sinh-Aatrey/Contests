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

// #define int int64_t
const int inf = 1e9 + 5, mod = 1e9 + 7, N = 1e5 + 5;

vector<int> squares;
vector<int> dp(N, -1);

void solve() {
    int n;
    scan(n);
    if (dp.back() == -1) {
        print(-1);
        return;
    }
    vector<int> ans(n);    
    int end = n - 1;
    while (end >= 0) {
        int start = dp[end];
        for (int i = start; i <= end; i++) {
            ans[i] = start + end - i;
        }
        end = start - 1;
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; squares.empty() || squares.back() < N; i++) {
        squares.emplace_back(i * i);
    }
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(squares.begin(), squares.end(), 2 * i);
        for (; it != squares.end(); it++) {
            int &sq = *it;
            if ((i == 0 || dp[i - 1] != -1) && sq - i < N) {
                dp[sq - i] = i;
            }
        }
    }
    int t = 1;
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}