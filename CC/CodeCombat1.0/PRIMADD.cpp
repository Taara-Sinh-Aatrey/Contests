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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 1e6 + 5;

int Pow(int a, int b, int P = mod){
    int res = 1;
    while(b > 0) {
        if(b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

// check for primes in n^(1/3) complexity
bool miller_rabin(int64_t n) {
    if (n < 2)
        return false;
 
    // Check small primes.
    for (int64_t p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
 
    int r = __builtin_ctz(n - 1);
    int64_t d = (n - 1) >> r;
 
    // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
    for (int64_t a : {2, 13, 23, 1662803}) {
        int64_t x = Pow(a % n, d, n);
 
        if (x <= 1 || x == n - 1)
            continue;
 
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = int64_t(uint64_t(x) * x % n);
 
        if (x != n - 1)
            return false;
    }
 
    return true;
}

void solve() {
    int low, high;
    scan(low, high);
    int ans = 0;
    for (int x = low; x <= high; x++) {
        ans += miller_rabin(x) ? x : 0;
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}