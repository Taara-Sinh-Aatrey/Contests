/**
 *    author:  Taara Sinh Aatrey
 *    created: 14.08.2021 18:37:16
**/

#include <bits/stdc++.h>
#include <type_traits>
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
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 1e6 + 5;
int cc = 0;

class dsu {
public:
    vector<int> p, sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        sz.resize(n, 0);
        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            if(sz[x] > sz[y]) {
                swap(x, y);
            }
            p[x] = y;
            cc -= (sz[x] > 0 && sz[y] > 0);
            sz[y] += sz[x];
            sz[x] = 0;
            return true;
        }
        return false;
    }
};


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

vector<int> cnt(N, 0);
dsu d(N);

void solve() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    
    int mn = INF;
    
    cc = 0;
    
    
    for(int i = 0; i < n; i++) {
        auto factors = factorise(a[i]);
        if(factors.empty()) {
            cc++;
            continue;
        }
        
        int p = d.get(factors[0].first);
        d.sz[p]++;
        if(d.sz[p] == 1) {
            cc++;
        }
        amin(mn, factors[0].first);
        
        for(int i = 1; i < factors.size(); i++) {
            d.unite(factors[0].first, factors[i].first);
        }    
    }
    
    for(int i = 0; i < n; i++) {
        auto factors = factorise(a[i]);
        if(factors.empty()) {
            continue;
        }
        
        for(int i = 0; i < factors.size(); i++) {
            int f = factors[i].first;
            d.p[f] = f;
            d.sz[f] = 0;
        }    
    }
    
    int ans = 2 * cc;    
    if(mn < INF) {
        amin(ans, mn * (cc - 1));        
    }
    
    cout << ans << '\n';
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