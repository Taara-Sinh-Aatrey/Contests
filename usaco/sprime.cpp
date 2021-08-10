/*
ID: taarasi1
TASK: sprime
LANG: C++14             
*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v) { for (T& x : v) is >> x; return is;} bool debug;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second;} template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { if(debug) { os << "{"; string sep; for (const T &x : v) os << sep << x, sep = ", "; os << '}'; } else { bool f = false; for (const T &x : v) { if(f) {os << " ";} os << x, f = true; } } return os;}
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
void dbg_out() { cerr << endl; } template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false
#endif

#define int int64_t
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 2e5 + 5;

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
    int n;
    cin >> n;
    
    vector<int> vec{2, 3, 5, 7};
    
    for(int l = 2; l <= n; l++) {
        vector<int> nvec;
        
        for(auto& x : vec) {
            for(int i = 1; i <= 9; i += 2) {
                int nx = x * 10 + i;
                if(miller_rabin(nx)) {
                    nvec.emplace_back(nx);
                }
            }
        }
        
        vec = nvec;
    }
    
    for(auto& x : vec) {
        cout << x << '\n';
    }
    
    
}

signed main()
{
#ifndef LOCAL
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    
    return 0;
}