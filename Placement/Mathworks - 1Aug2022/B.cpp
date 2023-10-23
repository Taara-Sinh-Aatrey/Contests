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

const int inf = 1e9 + 5, mod = 1e9 + 7;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int solve(int N) {
    const int MAX = 1 << N;
    vector<int> dp(MAX);
    dp[0] = 1;
    for (int mask = 0; mask < MAX; mask++) {
        int cnt = __builtin_popcount(mask);
        for (int i = 0; i < N; i++) {
            if (mask >> i & 1) {
                continue;
            }
            if ((i + 1) % (cnt + 1) == 0 || (cnt + 1) % (i + 1) == 0) {
                int new_mask = mask | (1 << i);
                dp[new_mask] += dp[mask];
            }
        }
    }
    return dp.back();
}

int main() {    
    print(solve(2));
    print(solve(3));
    print(solve(4));
    return 0;
}