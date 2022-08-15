#include "bits/stdc++.h"
using namespace std;

template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; for (const T &x : v) { if (f) os << " "; os << x; f = true; } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifdef AATREY_DEBUG
#include "debug.hpp"
#else
#define dbg(...)
#endif

const int inf = 1e9 + 5, mod = 1e9 + 7, N = 4e5 + 5;

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
        int64_t prod;
        for(int j = 0; j < (int) primes.size() && primes[j] <= spf[i] && (prod = primes[j] * int64_t(i)) < N; j++) {
            spf[prod] = primes[j];
            prime[prod] = false;
        }
    }
}

void prime_factorise(int num, vector<pair<int, int>> &prime_factors) {
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        while(spf[num] == factor) {
            num /= factor;
            cnt++;
        }
        prime_factors.emplace_back(factor, cnt);
    }
};

void factorise(int num, vector<int> &factors) {
    factors.emplace_back(1);
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        int p = 1;
        int sz = factors.size();
        while(spf[num] == factor) {
            num /= factor;
            p *= factor;
            for (int i = 0; i < sz; i++) {
                factors.emplace_back(factors[i] * p);
            }
            cnt++;
        }
    }
};

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}

void solve() {
    int l, r;
    scan(l, r);
    int len = r - l + 1;
    int64_t ans = (int64_t) len * (len - 1) * (len - 2) / 6;
    vector<int> cnt(r + 1);
    for (int i = l; i <= r; i++) {
        for (int j = i << 1; j <= r; j += i) {
            cnt[j] += 1;
        }
    }
    // subtract triplet(i, j, k) with lcm(i, j, k) = k
    for (int i = l; i <= r; i++) {
        ans -= (int64_t) cnt[i] * (cnt[i] - 1) / 2;
    }
    // subtract triplet(i, j, k) with lcm(i, j, k) = 2*k
    // bad triplets: i+j+k > 2*k => i+j > k
    // let 2k = x, now (i, j, k) must be divisors of x
    // k = x/2, what could be i and j
    // it turns out only (j = x/3, i = x/4) and (j = x/3, i = x/5) satisfies the condition
    {
        // case 1: x/4 >= l && x/2 <= r => x >= 4 * l && x <= 2 * r
        int low = 4 * l, high = 2 * r;
        low += 12 - ((low - 1) % 12 + 1);
        high -= high % 12;
        ans -= max<int>(0, (high - low) / 12 + 1);
    }
    {
        // case 2: x/5 >= l && x/2 <= r => x >= 5 * l && x <= 2 * r
        int low = 5 * l, high = 2 * r;
        low += 30 - ((low - 1) % 30 + 1);
        high -= high % 30;
        ans -= max<int>(0, (high - low) / 30 + 1);
    }
    print(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    sieve();
    scan(t);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}

