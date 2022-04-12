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

/*

1st: n >= k*(k+1)/2

2nd: n-(k*(k+1)/2) == 0 (mod k)
     n = k*(k+1)/2 (mod k) 

if k is even 
    n = k^2/2 + k/2 (mod k)
    n = k*x + k/2 (mod k), x = k/2
    n = k/2 (mod k)
    so 2n is a multiple of k but n is not a multiple of k
else
    n = k*(k+1)/2 (mod k)    n = k*y, y = (k+1)/2
    so, n is a multiple of k
    
now let's find an even candidate for k
    int even_k = 2;
    while (n % even_k == 0) {
        even_k *= 2;
    }
    this is the smalles k that satisfies the 2nd conditon

now how to find the smallest odd_k
    Do we really need to find the smallest one?
    first let's find the largest odd k
    int odd_k = n;
    while (odd_k % 2 == 0) {
        odd_k /= 2;
    }
    // or, odd_k = n / (even_k / 2)
    if (odd_k == 1) {
        // n is a power of 2 and the only odd divisor of n is 1
    }
    else {
        even_k / 2 * odd_k = n
        => even_k * odd_k = 2n
        claim: at least one of [odd_k, even_k] must satisfy the 1st condtion
        assume: even_k * (even_k + 1) / 2 > n
                even_k * (even_k + 1) > 2n
                
                odd_k < even_k + 1
                odd_k <= even_k
                odd_k <= even_k - 1
                odd_k + 1 <= even_k
                
                odd_k * (odd_k + 1) / 2 <= odd_k * even_k / 2 <= n  
    }

*/

void solve() {
    int n;
    scan(n);
    int even_k = 1;
    while (n % even_k == 0) {
        even_k *= 2;
    }
    int odd_k = n / (even_k / 2);
    if (odd_k == 1) {
        // n is a power of 2
        print(-1);
        return;
    }
    // since the mininum of them has the best chance of satisfying the 1st condition
    // and we know for a fact that atleast one of them must satisfy the 1st condition
    print(min(odd_k, even_k));
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