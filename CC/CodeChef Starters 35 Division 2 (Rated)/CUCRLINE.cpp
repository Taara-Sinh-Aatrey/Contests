/*
a,0
x,y

dx/dy = (x-a)/y

0, a/(a-x) * y

number of a > 0 such that
ay is a multiple of (a-x)

a-x = z, a > 0 or, z > -x
(z+x)*y is a multiple of z
(z*y + x*y) is a multiple of z
x*y is a multiple of z

y+(x*y/z) > 0
y > -x*y/z
1 > -x/z
1/x > -1/z

z > 0, 
z > -x

z < 0,
z < -x

z < -3

-3

6 -> -1, -2, 1, 2, 3, 6

z = -1
a-x = -1
a = x-1
a = 2


20 * a / (13 - 11)

1, 2, 4, 5, 10, 20



2*a % (a-3)
*/

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
const int inf = 1e18L + 5, mod = 1e9 + 7, N = 1e6 + 5;

vector<int> spf(N, 0);
vector<bool> prime(N, true);
vector<int> primes;
void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i < N; i++) {
        if(prime[i]) {
            spf[i] = i;
            primes.push_back(i);
        }
        int prod;
        for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * i) < N; j++) {
            spf[prod] = primes[j];
            prime[prod] = false;
        }
    }
}

void prime_factorise(int num, map<int, int> &prime_factors) {
    for (auto &p : primes) {
        if (p * p > num) {
            break;
        }
        while (num % p == 0) {
            prime_factors[p]++;
            num /= p;
        }
    }
    if (num > 1) {
        prime_factors[num]++;
    }
};

void solve() {
    int x, y;
    cin >> x >> y;
    map<int, int> pf;
    prime_factorise(x, pf);
    prime_factorise(y, pf);
    int ans = 1;
    for (auto &[a, b] : pf) {
        ans *= (b + 1);
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    sieve();
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}