#include "bits/stdc++.h"
using namespace std;

bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second;}
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "{"; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "}"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << "\n"; } template <typename Head, typename ...Tail> void dbg_out(const Head &H, const Tail &...T) { cerr << " " << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#else
#define dbg(...)
#endif

const int N = 2e7 + 1;
int cnt[N];
int64_t ans[N];

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

void solve() {
    sieve();
    int n;
    scan(n);
    for (int i = 0; i < n; i++) {
        int x;
        scan(x);
        vector<int> factors;
        factorise(x, factors);
        for (auto &f : factors) 
            cnt[f]++;
    }
    int64_t best = 0;
    for (int i = N - 1; i >= 1; i--) {
        ans[i] = cnt[i] * 1LL * i;
        for (auto &p : primes) {
            int j = i * p;
            if (j >= N) break;
            amax(ans[i], (cnt[i] - cnt[j]) * 1LL * i + ans[j]);
        }
        amax(best, ans[i] + n - cnt[i]);
    }
    print(best);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    return 0;
}