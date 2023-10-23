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

const int inf = 1e9 + 5, mod = 1e9 + 7;

string isPossible(int a, int b, int c, int d) {
    const int N = 1e3 + 5;
    vector<vector<bool>> dp(N, vector<bool>(N));
    dp[a][b] = true;
    for (int i = a; i <= c; i++) {
        for (int j = b; j <= d; j++) {
            if (dp[i][j]) {
                if (i + j <= c) {
                    dp[i + j][j] = true;
                }
                if (i + j <= d) {
                    dp[i][i + j] = true;
                }
            }
        }
    }
    return dp[c][d] ? "Yes" : "No";
}

int main() {
    print(isPossible(1, 1, 5, 2));
    print(isPossible(1, 4, 5, 9));
    print(isPossible(1, 2, 3, 6));
    return 0;
}