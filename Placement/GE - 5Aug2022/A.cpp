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

long double solve(int M, int MaxCashBack, int H) {
#define ld long double
    vector<ld> dp(H + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < M; i++) {
        vector<ld> ndp(H + 1, 0);
        for (int j = 0; j < M; j++) {
            int low = j + 1, high = j + MaxCashBack;
            ld prob = dp[j] / MaxCashBack;
            ndp[low] += prob;
            if (high < H) {
                ndp[high + 1] -= prob;
            }
            else {
                ndp[H] += prob * (high - H);
            }
        }
        for (int j = 1; j <= H; j++) {
            ndp[j] += ndp[j - 1];
        }
        for (int j = M; j <= H; j++) {
            ndp[j] += dp[j];
        }
        swap(dp, ndp);
    }
    return 1 - dp[H];
#undef ld
}

int main() {
    cout << fixed << setprecision(5);
    print(solve(1, 10, 6));
    print(solve(1, 10, 11));
    return 0;
}