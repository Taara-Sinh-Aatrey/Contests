/**
 *    author:  Taara Sinh Aatrey
 *    created: 13.08.2021 21:36:23
**/

#include <bits/stdc++.h>
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
const int mod = 1e9 + 7; const int INF = 1e18L + 5; const int N = 1e5 + 5;

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

void solve() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    
    int l = -1;
    int ans = 0;
    vector<int> last(N, -1);
    for(int i = 0; i < n; i++) {
        auto vec = factorise(a[i]);
        int mx = l;
        bool ok = false;
        for(auto& [p, f] : vec) {
            if(f > 1) {
                ok = true;
            }
            amax(mx, last[p]);
        }
        if(!ok) {
            ans += i - mx;
        }
        else {
            l = i;
        }
        for(auto& [p, f] : vec) {
            l = max(l, last[p]);
            last[p] = i;
        }
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