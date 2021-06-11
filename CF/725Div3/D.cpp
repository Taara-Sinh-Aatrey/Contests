/**
 *    author:  Taara Sinh Aatrey
 *    created: 10.06.2021 20:18:48
**/

#include <bits/stdc++.h>
using namespace std;

#define int int64_t

template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
    in >> a.first >> a.second;
    return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& a) {
    out << a.first << " " << a.second;
    return out;
}
template <class A, size_t S>
istream& operator>>(istream& in, array<A, S>& a) {
    for (A& x : a) in >> x;
    return in;
}
template <class A, size_t S>
ostream& operator<<(ostream& out, array<A, S>& a) {
    bool f = false;
    for (A& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (T& x : a) in >> x;
    return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    bool f = false;
    for (T& x : a) {
        if (f) out << " ";
        out << x;
        f = true;
    }
    return out;
}
void out(bool ok, bool cap = true) {
    if (cap) cout << (ok ? "YES" : "NO") << '\n';
    else cout << (ok ? "Yes" : "No") << '\n';
}
template <typename T, typename T1, typename... Tail>
T amax(T& a, T1 b, Tail... c) {
    if(b > a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amax(a, c...);
    }
    return a;
}
template <typename T, typename T1, typename... Tail>
T amin(T& a, T1 b, Tail... c) {
    if(b < a) a = b;
    if constexpr (sizeof...(c) != 0) {
        amin(a, c...);
    }
    return a;
}


const int mod = 1e9 + 7;
const int INF = 1e18L + 5;
const int N = 1e3 + 5;

vector<int> spf(N, 0);
// vector<int> unique_primes(N, 0);
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
    // for(int i = 2; i < N; i++) {
    //     int p = spf[i];
    //     unique_primes[i] = unique_primes[i / p] + ((i / p) % p != 0);
    // }
}

vector<pair<int, int>> factorise(int num) {
    vector<pair<int, int>> factors;
    while(num > 1) {
        int factor = spf[num];
        int cnt = 0;
        while(spf[num] == factor) {
            num /= spf[num];
            cnt++;
        }
        factors.emplace_back(factor, cnt);
    }
    return factors;
};

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
bool miller_rabin(unsigned n) {
    if (n < 2)
        return false;
 
    // Check small primes.
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;
 
    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;
 
    // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
    for (unsigned a : {2, 7, 61}) {
        unsigned x = Pow(a % n, d, n);
 
        if (x <= 1 || x == n - 1)
            continue;
 
        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);
 
        if (x != n - 1)
            return false;
    }
 
    return true;
}


void solve() {

    int a, b, k;
    cin >> a >> b >> k;

    int g = __gcd(a, b);

    auto factors = [&](int num) {
        int ret = 0;
        for(int p : primes) {
            if(p * p * p > num) {
                break;
            }
            while(num % p == 0) {
                num /= p;
                ret++;
            }
        }
        if(num > 1) {
            // a number 'n' can have atmost 2 factors greater than n^(1/3)
            ret += miller_rabin(num) ? 1 : 2;
        }
        return ret;
    };


    int sp = (a != g) + (b != g);
    int fa = factors(a), fb = factors(b);
    int mn = (a != 1) + (b != 1);
    int mx = fa + fb;

    out(sp == k || (mn <= k && k <= mx));

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
    
    return 0;
}